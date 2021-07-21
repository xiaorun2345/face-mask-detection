#include "utils.h"
#include<string.h>
// send protobuf data

/*
bool is_pt_in_polygon(Point2d pt, Polygon roi)
{
  int maxX = -1, maxY = -1, minX = INT_INF_MAX, minY = INT_INF_MAX;
  int i, j;
  float x;
  bool flag = false;

  for (int i=0; i<roi.count; i++)
  {
    maxX = std::max(roi.points[i].x , maxX);
    maxY = std::max(roi.points[i].y , maxY);
    minX = std::min(roi.points[i].x , minX);
    minY = std::min(roi.points[i].y , minY);   
  }
  if(pt.x < minX || pt.x > maxX || pt.y < minY || pt.y > maxY)
  {
    return false;
  }

  for(i=0, j=roi.count-1; i<roi.count; j=i++)
  {
    if((roi.points[i].y > pt.y) != (roi.points[j].y > pt.y))
    {
      x = (roi.points[j].x-roi.points[i].x) * (pt.y-roi.points[i].y) * 1.0 / (roi.points[j].y - roi.points[i].y) + roi.points[i].x;
      if (pt.x < x)
        flag = !flag;
    } 
  }

  return flag;
}
*/

void sender_protobuf_data(char *buf, NLConfig *config, int socketID, struct sockaddr_in addr_serv, int scoket_len)
{
    int len=strlen(buf);
    //g_print("buf size:%d\n",len);
    char *pbuf=(char *)malloc(len+4);
    pbuf[0] = 0xDA;
    pbuf[1] = 0xDB;
    pbuf[2] = 0xDC;
    pbuf[3] = 0xDD;
    memcpy(pbuf+4,buf,len);
    int send_num = sendto(socketID, pbuf, len+4, 0, (struct sockaddr*)&addr_serv, scoket_len);
    if(send_num < 0)
    {
      g_print("sendto error\n");
    }
    free(pbuf);


}


