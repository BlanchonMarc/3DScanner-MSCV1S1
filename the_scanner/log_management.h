//#ifndef LOG_MANAGEMENT_H
//#define LOG_MANAGEMENT_H


////----------------------------------------------------------------------
//// Includes
////----------------------------------------------------------------------
////Including QString to manage files as string
//#include <QString> // To differentiate user inputs and inner program string
//#include <fstream>


///*
//  log_management class will be used to display and write in defined files during processes and also display on console

//  The class is developped in a special manner. Using streams to create the file and use
//  class functions and overload to manipulate the file
//  It is maybe not optimized but it help understanding the code and also class management
//  It also allow to cut in separated parts all the process and make checks if necessary
//  If the class is less optimized than using all the functions of sreams there is multiple reasons
//    - It is in a project developpement with c++ beginners
//    - Better understanding
//    - The efficiency is not that much impacted by the change

//  To be 100% coherent, we have to manage files so we have to take care of everylines and access right

//  If the program had to be optimized, in fact it wasn't necessary to use class to separate the process
//  and we can use definetly all the functionnalities of streams, that avoid overloading of operators,
//  functions creations and everything because all is embedded. But this is a class project so ...

//  ///Constructors  /// Each incrementation of inputs gives more precise definition the process remain the same
//        @NULL :: Creating default file with default convention and default target
//        @QString u_path :: Changing the targeted folder
//        @QString u_path, QString u_filename :: Changing the name of the output file
//        @QString u_path, QString u_filename, QString u_extansion :: Changing convention

//  ///Destructor
//        @NULL :: Closing the file opened

//  ///Operators
//        @<< :: Writing on log file and console
//        @<<< :: Writing on log file and console file but implementing a timer to get duration // TO DO

//  ///Function
//        GetCurrentWorkingDir :: return the current directory path we are working on
// */

//class log_management
//{
//public:
//    //Constructors
//    log_management();
//    log_management(const QString& u_path);
//    log_management(const QString& u_path, const QString& u_filename);
//    log_management(const QString& u_path, const QString& u_filename, const QString& u_extansion);
//    //Destructors
//    ~log_management();

//    //Functions
//        //get current path
//    std::string GetCurrentWorkingDir( void );

//    //Operator

//    log_management& operator<<(  log_management& u_log,  const std::string& u_write  );

//private:

//    //File
//    std :: string = m_path ; //Path of the file
//    std :: string = m_filename; //Name of the file
//    std :: ofstream = m_stream; //Output Stream
//};

//#endif // LOG_MANAGEMENT_H
