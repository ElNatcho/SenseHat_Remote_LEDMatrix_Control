# SenseHat_Remote_LEDMatrix_Control

Das SenseHat_Remote_LEDMatrix_Control-Projekt dient dazu die LED-Matrix des SenseHat Add-on Boards fernzusteuern.
Es besteht aus drei Unterprojekten

## 1.)RemLEDMatrix_Server:

Der RemLEDMatrix_Server läuft auf dem Raspberry Pi mit dem SenseHat. Die Anwendung empfängt UDP-Pakete, welche die nötigen 
Informationen beinhalten um die LED-Matrix zu kontrollieren, und benutzt diese Pakete um die Matrix zu steuern.
Um den Server zu starten muss als Kommandozeilenparameter eine Konfigurationsdatei übergeben werden:

RemLEDMatrix_Server "Conf_File"

In der Konfig-Datei befindet sich der Port des Servers und der Framebuffer des SenseHats:  
In meinem Fall:  
"server.conf":  
1 10000     (In der ersten Zeile MUSS der Port angegeben werden)  
2 /dev/fb1  (In der zweiten Zeile MUSS der Framebuffer angegeben werden)  

## 2.)RemLEDMatrix_Client:

Der RemLEDMatrix_Client ist die erste Version des Clients mit welchem man mit dem Server kommunizieren kann.  
Pro: -Man kann die LED-Matrix fernsteuern  
Con: -Die IP/der Port des Servers ist fest einprogrammiert  

![client1](https://cloud.githubusercontent.com/assets/21142935/25269229/08ff07d8-267c-11e7-8843-d160b4cc8621.PNG)

## 3.)RemLEDMatrix_Client_2:

Der RemLEDMatrix_Client_2 ist die verbesserte Version des RemLEDMatrix_Clients.  
Pro: -Man kann die LED-Matrix fernsteuern  
     -Man muss die IP/den Port des Servers manuell eingeben  
     
![client2](https://cloud.githubusercontent.com/assets/21142935/25269228/08fefa54-267c-11e7-9721-4ae58adf22eb.PNG)

### Verwendete Bibliotheken:
-SFML 2.4
-boost 1.64
