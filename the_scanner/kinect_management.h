#ifndef KINECT_MANAGEMENT_H
#define KINECT_MANAGEMENT_H



#define NOMINMAX
#include <Windows.h>
#include <Kinect.h>

#include <pcl/io/boost.h>
#include <pcl/io/grabber.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

class Kinect_Management
{
public:
    Kinect_Management();
};








namespace pcl // Pcl namespace, to avoid placing pcl everytime in the code //Bad way of using a namespece because the code is embeded in braces
{
    struct pcl::PointXYZ;
    struct pcl::PointXYZI;
    struct pcl::PointXYZRGB;
    struct pcl::PointXYZRGBA;
    template <typename T> class pcl::PointCloud;

    template<class Interface> //template class directly instancied in the h to avoid linking error
    inline void SafeRelease( Interface *& IRelease )
    {
        if( IRelease != NULL ){
            IRelease->Release();
            IRelease = NULL;
        }
    }

    class Kinect2Grabber : public pcl::Grabber // Kinect grabber publicly inherited from Grabber
    {
        public:
            Kinect2Grabber();// constructor
            virtual ~Kinect2Grabber() throw ();//destructor
            //Virtual functions
            virtual void start();
            virtual void stop();
            virtual bool isRunning() const;
            virtual std::string getName() const;
            virtual float getFramesPerSecond() const;

            typedef void ( signal_Kinect2_PointXYZ )( const boost::shared_ptr<const pcl::PointCloud<pcl::PointXYZ>>& );
            typedef void ( signal_Kinect2_PointXYZI )( const boost::shared_ptr<const pcl::PointCloud<pcl::PointXYZI>>& );
            typedef void ( signal_Kinect2_PointXYZRGB )( const boost::shared_ptr<const pcl::PointCloud<pcl::PointXYZRGB>>& );
            typedef void ( signal_Kinect2_PointXYZRGBA )( const boost::shared_ptr<const pcl::PointCloud<pcl::PointXYZRGBA>>& );

        protected:
            //pointers to signal, belknging to boost
            boost::signals2::signal<signal_Kinect2_PointXYZ>* signal_PointXYZ;
            boost::signals2::signal<signal_Kinect2_PointXYZI>* signal_PointXYZI;
            boost::signals2::signal<signal_Kinect2_PointXYZRGB>* signal_PointXYZRGB;
            boost::signals2::signal<signal_Kinect2_PointXYZRGBA>* signal_PointXYZRGBA;
            //Pointer to clouds
            pcl::PointCloud<pcl::PointXYZ>::Ptr convertDepthToPointXYZ( UINT16* depthBuffer );
            pcl::PointCloud<pcl::PointXYZI>::Ptr convertInfraredDepthToPointXYZI( UINT16* infraredBuffer, UINT16* depthBuffer );
            pcl::PointCloud<pcl::PointXYZRGB>::Ptr convertRGBDepthToPointXYZRGB( RGBQUAD* colorBuffer, UINT16* depthBuffer );
            pcl::PointCloud<pcl::PointXYZRGBA>::Ptr convertRGBADepthToPointXYZRGBA( RGBQUAD* colorBuffer, UINT16* depthBuffer );

            boost::thread thread;
            mutable boost::mutex mutex; // type mutable, and mutex, this is type of process that can be locked for security

            void threadFunction();

            bool quit;
            bool running;
            // HResult is a check !! Care it's a windows type that return S_OK if the process goes well, kind of boolean common to all applications
            // This is a special type
            HRESULT result;
            IKinectSensor* sensor;
            ICoordinateMapper* mapper;
            IColorFrameSource* colorSource;
            IColorFrameReader* colorReader;
            IDepthFrameSource* depthSource;
            IDepthFrameReader* depthReader;
            IInfraredFrameSource* infraredSource;
            IInfraredFrameReader* infraredReader;

            int colorWidth;
            int colorHeight;
            std::vector<RGBQUAD> colorBuffer;

            int depthWidth;
            int depthHeight;
            std::vector<UINT16> depthBuffer;

            int infraredWidth;
            int infraredHeight;
            std::vector<UINT16> infraredBuffer;
    };

}

#endif // KINECT_MANAGEMENT_H
