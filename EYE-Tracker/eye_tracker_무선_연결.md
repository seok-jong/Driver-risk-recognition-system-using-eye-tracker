# eye tracker 무선 연결

obii Pro Glasses 2를 컴퓨터의 Pro Glasses Controller 소프트웨어에 연결하는 방법을 알아보십시오.

**Tobii Pro 안경 컨트롤러** 는 Tobii Pro 안경 2 시선 추적기의 대부분의 기능을 제어하는 데 사용되는 소프트웨어입니다. 녹화, 보정 및 라이브보기와 같은 Pro Glasses Controller가 Pro Glasses 2와 정보를주고받을 수 있으려면 녹음 장치와 Pro Glasses Controller를 실행하는 태블릿 / 컴퓨터가 서로 연결되어 있어야합니다. WLAN (무선) 또는 이더넷 케이블 (이더넷 케이블을 사용하는 경우 Pro Glasses Controller를 실행하는 태블릿에 USB / LAN 어댑터를 설치해야 함)을 통해 연결을 설정할 수 있습니다. 녹음 장치는 네트워크 액세스 포인트로 작동하며 Tobii 안경 컨트롤러 소프트웨어를 실행하는 컴퓨터는 컴퓨터가 네트워크에 연결하는 방식과 유사한 방식으로 연결됩니다.

# Pro Glasses Controller를 실행하는 태블릿 / 컴퓨터를 녹음 장치에 무선으로 연결하려면 :

1. Pro Glasses 2 레코딩 유닛을 켜고 헤드 유닛을 연결하십시오.
2. Pro Glasses Controller를 설치 한 컴퓨터 / 태블릿을 켭니다.
3. Windows 8 / 8.1에서 화면 오른쪽 가장자리에서 손가락을 안쪽으로 밀어 참 바를 엽니 다.
4. 참 바에서 설정을 탭합니다.
5. 무선 네트워크 아이콘을 누릅니다. 사용 가능한 네트워크 목록이 나타납니다. (새로 시작된 녹음 장치가 사용 가능한 네트워크 목록에 나타나기까지 최대 2 분이 소요될 수 있습니다.
6. 태블릿 / 컴퓨터가 이미 다른 네트워크 (WLAN / 인터넷 / LAN 연결 등)에 연결되어있는 경우 연결을 끊으십시오.
    
    이 네트워크에서 먼저. 그렇지 않으면 태블릿이 컴퓨터에 자동으로 다시 연결되지 않을 수 있습니다.
    
    연결이 끊어진 후 녹음 장치.
    
7. 녹음 장치 (TG02X-XXX ...)의 일련 번호와 이름이 같은 WLAN 네트워크를 누릅니다. 당신은
    
    녹음 장치 뒷면의 스티커에서 일련 번호를 찾으십시오.
    
8. 녹음 장치에 항상 자동으로 연결하려면 자동으로 연결 확인란을 선택합니다.
9. 
    
    연결을 탭합니다.
    
10. 네트워크 보안 키 필드에 WLAN 암호, *TobiiGlasses*
    
    를 입력하고 다음을 누릅니다. 최대 2 분이 소요될 수 있습니다.
    
    Pro Glasses Controller가 녹음 장치에 연결하기 전에.
    
11. Pro 안경 컨트롤러에서
    
    대시 보드를 선택하면 안경 제어판에 "준비"가 표시됩니다.
    
    소프트웨어 및 녹음 장치. 이제 Pro Glasses 2로 녹화 할 준비가되었습니다.
    
    **client.py**
    
    ```
    #!/usr/bin/python
    import socket
    import cv2
    import numpy
    TCP_IP = 'localhost'
    TCP_PORT = 5001
    sock = socket.socket()
    sock.connect((TCP_IP, TCP_PORT))
    capture = cv2.VideoCapture(0)
    ret, frame = capture.read()
    encode_param=[int(cv2.IMWRITE_JPEG_QUALITY),90]
    result, imgencode = cv2.imencode('.jpg', frame, encode_param)
    data = numpy.array(imgencode)
    stringData = data.tostring()
    sock.send( str(len(stringData)).ljust(16));
    sock.send( stringData );
    sock.close()
    decimg=cv2.imdecode(data,1)
    cv2.imshow('CLIENT',decimg)
    cv2.waitKey(0)
    cv2.destroyAllWindows() 
    ```
    
    **server.py**
    
    ```
    #!/usr/bin/python
    import socket
    import cv2
    import numpydef recvall(sock, count):
        buf = b''
        while count:
            newbuf = sock.recv(count)if not newbuf: return None
            buf += newbuf
            count -= len(newbuf)return buf
    TCP_IP = 'localhost'
    TCP_PORT = 5001
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((TCP_IP, TCP_PORT))
    s.listen(True)
    conn, addr = s.accept()
    length = recvall(conn,16)
    stringData = recvall(conn, int(length))
    data = numpy.fromstring(stringData, dtype='uint8')
    s.close()
    decimg=cv2.imdecode(data,1)
    cv2.imshow('SERVER',decimg)
    cv2.waitKey(0)
    cv2.destroyAllWindows() 
    ```