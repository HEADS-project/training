package gr.atc.heads;

import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathFactory;

import org.kevoree.annotation.ComponentType;
import org.kevoree.annotation.Input;
import org.kevoree.annotation.Output;
import org.kevoree.annotation.Param;
import org.kevoree.annotation.Start;
import org.kevoree.annotation.Stop;
import org.kevoree.annotation.Update;
import org.kevoree.api.Port;
import org.kevoree.log.Log;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

@ComponentType
public class Sender {
	
	@Param(defaultValue = "http://hestia.atc.gr/NewsMLs.xml")
	private String newsUrl;
	
	@Start
	public void start() {
		Log.info("Sender starts");
		timer.send("");
	}
	
	@Stop
	public void stop() {
		Log.info("Sender stops");
	}
	
	@Update
	public void update() {
		Log.info("Update. NewsURl: {}", newsUrl);
	}
	
	@Output
	private Port newsPort;
	
	@Output
	private Port timer;	
	
	@Input
	private void poll(Object msg) {
		List<NewsMLItem> items = getNewsML(newsUrl);
		for(NewsMLItem item: items) {
			String message = String.format("%s-%s", item.getTopic(), item.getNewsItemId());
			newsPort.send(message);
		}
	}
	
	private final String USER_AGENT = "Mozilla/5.0";
	
	private List<NewsMLItem> getNewsML(String url) {
		try {
			URL obj = new URL(url);
			HttpURLConnection con = (HttpURLConnection) obj.openConnection();
			con.setRequestMethod("GET");
			con.setRequestProperty("User-Agent", USER_AGENT);
	 
			int responseCode = con.getResponseCode();
			System.out.println("\nSending 'GET' request to URL : " + url);
			System.out.println("Response Code : " + responseCode);
	 
			Document doc = parse(con.getInputStream());

			return parseDocument(doc);
		} catch(Exception ex) {
			System.err.println(ex.getMessage());
		}
		return null;
	}
	
	private List<NewsMLItem> parseDocument(Document doc){
		List<NewsMLItem> newsItems = new ArrayList<NewsMLItem>();
		
		XPath xPath =  XPathFactory.newInstance().newXPath();
		String idExpression = "NewsItem/Identification/NewsIdentifier/NewsItemId";
		Element docEle = doc.getDocumentElement();
		NodeList nl = docEle.getElementsByTagName("NewsML");
		if(nl != null && nl.getLength() > 0) {
			for(int i = 0 ; i < nl.getLength();i++) {
				Element el = (Element)nl.item(i);
				NewsMLItem item = new NewsMLItem();
				
				NodeList topics = el.getElementsByTagName("TopicSet");
				if (topics.getLength() > 0) {
					item.setTopic(((Element) topics.item(0)).getAttribute("FormalName"));
				}
				
				try {
					String id = xPath.compile(idExpression).evaluate(el);
					item.setNewsItemId(id);
				}
				catch (Exception ex) {
					System.err.println(ex.getMessage());
				}
				
				newsItems.add(item);
			}
		}
		
		return newsItems;
	}
	
	private Document parse(InputStream in) throws Exception {
		DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
		DocumentBuilder db = dbf.newDocumentBuilder();
		return db.parse(in);
	}
}
