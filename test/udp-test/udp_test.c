#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/if.h>

int main()
{	
	//	struct ip_mreqn {
	//		struct in_addr	imr_multiaddr;			/* IP multicast address of group */
	//		struct in_addr	imr_address;			/* local IP address of interface */
	//		int 			imr_ifindex;			/* Interface index */
	//	};
	char *ifname="ens33";
	struct ip_mreqn mreq;
	mreq.imr_ifindex=if_nametoindex(ifname);
	printf("ifindex of ens33:%d\n",mreq.imr_ifindex);
	/*使用多播发送数据前，应该设置多播的默认发送ip地址*/
	//setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_IF, &group, sizeof(group));  /*获取组播权限*/
}
