//#include "log_management.h"

///*
//Standard way of getting current path used in default constructor
//Example from cplusplus.com
//*/
//#include <stdio.h>  // defines FILENAME_MAX
//#define WINDOWS  //Comment this line for linux, else let it uncommented
//#ifdef WINDOWS
////#include <direct.h>
//#define GetCurrentDir _getcwd //Defining flags to get the path
//#else
//#include <unistd.h> //Including file to get path
//#define GetCurrentDir getcwd //Defining also another flag
//#endif
//#include<iostream>
///*
//End of includes for current path
//*/

//#include <fstream>
//#include <ctime>



////Constructors
//log_management::log_management(){

//    m_filename = "log.txt"; // defaul file name
//    m_path = log_management::GetCurrentWorkingDir()+ m_filename; // default path current directory
//    ofstream t_output(m_path , ios :: out); // Create the file and stream
//    m_stream = t_output ; //Copy of the path, more easy to manage inside the class and use copy to avoid linking errors

//}


//log_management::log_management(const QString& u_path){


//    m_filename = "log.txt"; // defaul file name
//    m_path = u_path.toStdString() + m_filename; //  path converted in std string
//    ofstream t_output(m_path , ios :: out); // Create the file and stream
//    m_stream = t_output ; //Copy of the path, more easy to manage inside the class and use copy to avoid linking errors


//}


//log_management::log_management(const QString& u_path, const QString& u_filename){


//    m_filename = u_filename.toStdString() + ".txt"; // file name converted to std string
//    m_path = u_path.toStdString()+ m_filename; //  path converted in std string
//    ofstream t_output(m_path , ios :: out); // Create the file and stream
//    m_stream = t_output ; //Copy of the path, more easy to manage inside the class and use copy to avoid linking errors

//}


//log_management::log_management(const QString& u_path, const QString& u_filename, const QString& u_extansion){


//    m_filename = u_filename.toStdString() + u_extansion.toStdString(); // file name converted to std string
//    m_path = u_path.toStdString()+ m_filename; //  path converted in std string
//    ofstream t_output(m_path , ios :: out); // Create the file and stream
//    m_stream = t_output ; //Copy of the path, more easy to manage inside the class and use copy to avoid linking errors


//}


////Destructors
//log_management::~log_management(){

//    m_stream.flush();
//    m_stream.close();

//}


////Functions

//log_management:: std::string GetCurrentWorkingDir( void ){

//    char buff[FILENAME_MAX]; // Allocate a temporary buffer constructed using FILENAME_MAX member of stdio.h
//    GetCurrentDir( buff, FILENAME_MAX ); //Use function to get our path that change our buff
//    std::string current_working_dir(buff); // Cast a new string to get our path
//    return current_working_dir; //return the path as string

//}



////Operator

//log_management :: log_management& operator>>(  log_management& u_log,  const std::string& u_write  ){

//    time_t t_time;// Importing the time // TO DO
//    time(&t_time);


//    std::cout << u_write; // Output console
//    u_log.m_stream << u_write << std::flush; //Output File
//    return u_log;

//}

