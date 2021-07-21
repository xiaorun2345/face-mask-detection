#ifndef  __UTILS_H__
#define  __UTILS_H__

#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <math.h>
#include <arpa/inet.h>
#include <time.h>
#include<gst/gst.h>
//#include <algorithm>
#define MAX_PACKET_SIZE         1024
#define DISTANCEPSEC            30.83
#define PI                      3.1415926535898
#define PI2                     6.2831853071796
// #define INTERVAL                3               //the interval time for calculate speed 
#define MAX_TRAJECTORY_LEN      21
#define MAX_TRACK_AGE           200             // max age for a track obj
#define MAX_SHADOW_TRACKING_AGE 5               //
#define MIN_SPEED_THRESH        2.
#define MIN_POINT_NUM_FIT       3
#define MIN_EPSILON_FLOAT       (1e-6)
#define LANE_ID_MAX_LEN         64
#define FLOAT_INF_MAX           (1.e30) 
#define INT_INF_MAX             (1e6)

#define MAX_LANE_COUNT          8  
#define MAX_LINK_COUNT          4              
#define MAX_POINTS_NUM          32

#ifdef __cplusplus
extern "C"
{
#endif

enum objType 
{
  UNKNOWN=0, 	  // 未知
  FACE_MASK=1,
  FACE=2
};

typedef struct _point2d
{
  gint x;
  gint y;
}Point2d;

typedef struct _point2f 
{
  gfloat x;
  gfloat y;
}Point2f;

typedef struct _polygon
{
  Point2d points[MAX_POINTS_NUM];
  gint count;
}Polygon;


typedef struct _nl_config
{
  gchar*  camera_sensor;  // camera device id
  gchar*  camera_ip;         // camera ip
  gchar*  local_ip;          // local ip
  gint    local_port;        // local port
  gchar*  rsu_ip;            // rsu ip
  gint    rsu_port;          // port for send data to rsu
  Polygon roi_points;        // roi rect points
}NLConfig;


typedef struct _trackObj 
{
  float cx;              //top left point
  float cy;
  float w;
  float h;
  guint64 timestamp;    //ns
}classObj;


// void sender_protobuf_data(GList* list, gchar* camera_sensor_id, gdouble alpha);
// void sender_protobuf_data(GList* list, gchar* camera_sensor_id, gdouble alpha, gint lane_count, Lane* lanes, int socketID, struct sockaddr_in addr_serv, int scoket_len);
void sender_protobuf_data(char *buf, NLConfig *config, int socketID, struct sockaddr_in addr_serv, int scoket_len);


//bool is_pt_in_polygon(Point2d pt, Polygon roi);

#ifdef __cplusplus
}
#endif

#endif
