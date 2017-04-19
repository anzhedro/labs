import java.util.*;
import java.io.*;
import java.net.*;

public class Zad1 {

	public static String userName = new String("fpm.androsikei");
	public static String password = new String("2032490q");

	public static void main(String[] args) {

		Proxy proxy = new Proxy(Proxy.Type.HTTP, new InetSocketAddress("proxy.bsu", 3128));
		Authenticator authenticator = new Authenticator() {
			public PasswordAuthentication getPasswordAuthentication() {
				if (getRequestorType() != Authenticator.RequestorType.SERVER)
					return (new PasswordAuthentication(userName,
							password.toCharArray()));
				else
					return null;
			}
		};

		try {
			URL url = new URL("http://www.gutenberg.org/cache/epub/3537/pg3537.txt");
			Authenticator.setDefault(authenticator);
			HttpURLConnection connection = (HttpURLConnection) url
					.openConnection(proxy);
			connection.setRequestMethod("GET");
			connection.setRequestProperty("Accept", "text/plain;text/html");
			BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
			String inputLine;
			while ((inputLine = in.readLine()) != null) {
				System.out.println(inputLine);
			}

			Map<String, List<String>> msl = connection.getHeaderFields();
			Set<String> setK = msl.keySet();
			Iterator<String> it = setK.iterator();
			String key = new String();
			while (it.hasNext()) {
				key = it.next();
				System.out.println(key + " = " + msl.get(key));
			}
			in.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}

