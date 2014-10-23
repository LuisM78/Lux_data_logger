import processing.serial.*;
Serial mySerial;
PrintWriter output;
void setup() {
   mySerial = new Serial( this, Serial.list()[1], 9600 );
   println(Serial.list());
   //Date = (Date and Time)
   output = createWriter( "data.txt" );
     textSize(30);
  size(800, 600);
  background(80, 120, 255);

}
void draw() {
    if (mySerial.read() == 255 ) {
         //String value = mySerial.readString();
          
         
         //int ID =  mySerial.read(); 
         int low1 = mySerial.read();
         int hi1 = mySerial.read();
         int low2 = mySerial.read();
         int hi2 = mySerial.read();
         //int check = mySerial.read();
//         int low1b = mySerial.read();
//         int hi1b = mySerial.read();
//         int low2b = mySerial.read();
//         int hi2b = mySerial.read();
         //
//         int low1c = mySerial.read();
//         int hi1c = mySerial.read();
//         int low2c = mySerial.read();
//         int hi2c = mySerial.read();
         
         int check = mySerial.read();
         
         
        
         
         
         int number1 = hi1*256+low1;
         //print(number1);
         int number2 = hi2*256+low2;
         
         int value = 256*number2 + number1;
         //print(value);
         
//         int number1b = hi1b*256+low1b;
//         //print(number1);
//         int number2b = hi2b*256+low2b;
//         
//         int valueb = 256*number2b + number1b;
         
         
//         int number1c = hi1c*256+low1c;
//         //print(number1);
//         int number2c = hi2c*256+low2c;
//         
//         int valuec = 256*number2c + number1c;

         
         
         //print(value);

         
         
         
         int checksum = low1 + hi1 +low2 +hi2;// +  low1b + hi1b +low2b +hi2b ;//    + low1c + hi1c +low2c +hi2c       ; 
         print("the check is");
         print(check);     
       
         
         
         print("the checksum is");
         print(checksum);
         
         checksum = checksum % 256; // extracts the module
         print("checksumis");
         println(checksum);
         //int checksum = mySerial.read();
         //int check = ID+int(value);
         //print(ID);
         //print(checksum);
         
         if (checksum == check)  {
               updateValue(int(value),int(valueb));//,int(valuec));
               output.print(month() + "/" + day() + "/" + year() + " " + hour() + ":" + minute() + ":" + second() );
               output.println(","+ value)// +","+valueb);//+","+valuec);
         }
         
          }
      }  

void updateValue(int value)//, int valueb)//, int valuec)
{
   
   fill(0,255,0);
   rect(10,200,300, 100);
   fill(0);
   text(value+"lux",35,230);
   //text(valueb+"lux",35,260);
   //text(valuec+"Lux",35,285);
   output.flush();
   
}

void keyPressed() {
    output.flush();  // Writes the remaining data to the file
    output.close();  // Finishes the file
    exit();  // Stops the program
}
