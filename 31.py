import scapy.all as scapy

def scan(ip_range):
    arp_request = scapy.ARP(pdst=ip_range)
    broadcast = scapy.Ether(dst="ff:ff:ff:ff:ff:ff")
    arp_request_broadcast = broadcast / arp_request
    answered_list = scapy.srp(arp_request_broadcast, timeout=1, verbose=False)[0]

    print("IP Address\t\tMAC Address")
    print("---------------------------------")
    for answer in answered_list:
        print(answer[1].psrc + "\t\t" + answer[1].hwsrc)

# Example: Scan the local network (Change to your network range)
scan("192.168.1.1/24")