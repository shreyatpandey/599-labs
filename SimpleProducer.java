import java.io.*;
import java.lang.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
//import util.properties packages
import org.apache.kafka.clients.producer.Producer;
//import simple producer packages
import org.apache.kafka.clients.producer.KafkaProducer;
//import KafkaProducer packages
import org.apache.kafka.clients.producer.ProducerRecord;
//import ProducerRecord packages
public class SimpleProducer {
//Create java class named SimpleProducer
		public static void main(String[] args) throws Exception{
		
		    for(int i=0;i<20;i++)
		    {
		    
		     
		         File dirName = new File("/home/student/Downloads/kafka_new/lab10/file_"+Integer.toString(i+1)+".txt");
		         String st = null;
		       while(!(dirName.exists()))
		        {
		          continue;
		          }
		          
		          if(dirName.exists())
		          {
		          Properties props = new Properties();
				//Assign localhost id 
				props.put("bootstrap.servers","localhost:9092");
				//Set acknowledgements for producer requests
				props.put("acks","all");
				//If the request fails, the producer can automatically retry,
				props.put("retries", 0);
				//Specify buffer size in config
				props.put("batch.size", 16384);
				//Reduce the no of requests less than 0
				props.put("linger.ms", 1);
				//The buffer.memory controls the total amount of memory available to the producer for buffering.
				props.put("buffer.memory", 33554432);
				props.put("key.serializer", "org.apache.kafka.common.serialization.StringSerializer");
				props.put("value.serializer", "org.apache.kafka.common.serialization.StringSerializer");
		
		           Scanner scan = new Scanner(dirName);
		           
		            String topicName = scan.nextLine();
		            System.out.println(topicName);
		            String num_store = scan.nextLine();
		            System.out.println(num_store);
		            
			         Producer<String,String> producer = new KafkaProducer<String,String>(props);
		            producer.send(new ProducerRecord<String,String>(topicName,Integer.toString(i),num_store));
		            System.out.println("Message sent successfully");
		            producer.close();
		            
		        
		      }
		      
		

}
}
}
