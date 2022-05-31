# yolo customizing 방법 및 연습

handle ,side_side_mirror ,right_side_handle ,room_mirror ,center_fascia ,car ,instrument_panel

위 7개 항목을 인식하는 yolo 가중치파일을 만들야 한다. 

시뮬레이터에서 영상을 녹화한 후 (실내는 실제, 실외는 모니터상의 ucwin) yolo marker를 이용하여 가중치 파일을 만든다. 

영상을 프레임별로 분리한 후 yolo marker에 적용 

---

★ ffmpeg 사용법 (cmd 창에서)

1. 동영상이 있는 경로로 이동(해당 경로에 frame이 저장되므로 폴더에 넣어놓은 후 실행 할 것을 추천 ) 

2. 명령어 입력

1) ffmpeg -i [ 동영상 제목.확장자 ] -vf fps=[ 1초당 x 프레임으로 잘라져서 저장됨 ] [ 저장되는 번호의 순서 or 이름 설정 ]%d.jpg 

2) ffmpeg -i [ Inner_pocket1.mp4 ] -vf fps=[ 31 ] [ 0 ]%d.jpg

3) ffmpeg -i Inner_pocket1.mp4 -vf fps=31 0%d.jpg ( 최종 코드 예시 )

![https://blog.kakaocdn.net/dn/bd8Tv1/btqxXKS60cZ/gsw7FMLCBAJA0wpyC21R71/img.png](https://blog.kakaocdn.net/dn/bd8Tv1/btqxXKS60cZ/gsw7FMLCBAJA0wpyC21R71/img.png)

---

### yolo mark 다운 & Labeling

[AlexeyAB/Yolo_mark](https://github.com/AlexeyAB/Yolo_mark)

위 링크에서 yolo mark를 다운받는다. 

1. 압축을 풀고 yolo_mark.sln 을 실행한다. 
2. 1)프로젝트 속성에서 c/c++ - 일반 - 추가포함 디렉터리에 C:\opencv\build\include를 추가 
    
    2)링커-일반-추가 라이브러리 디렉터리에 C:\opencv\build\x64\vc14\lib를 추가
    
3. F5를 눌러 빌드. 
4. x64 - Release - data 에서 
    
    1) obj.data파일에서 classes 를 자신이 원하는 classes갯수로 수정한다.  
    
    2) [obj.name](http://obj.name)s 에서 classes의 갯수대로 이름을 입력한다. 
    
    3)train.txt 파일의 모든 내용을 지운다.
    
5.  img폴더에 jpg데이터를 넣는다.(jpg만 호환!!!!!!!!)
6. 이후에 yolo_mark.cmd를 클릭하여 YOLO Mark 실행
7. 이후에 수많은 사진을 열심히 boxxing한다. 
8. boxxing을 마치면 obj.data , obj.names , train.txt ,img폴더를

darknet-master\build\darknet\x64\data 에 옮긴다. 

 9. cfg폴더의 yolov3.cfg파일을 복사하여 x64로 옮긴후 

    yolo-obj.cfg로 이름을 변경한 후 열어서  Line 610,696,783 의 classes를 수정해주고 

                                                                      Line 603, 689, 776의 filters =(N+5)*3으로 수정 (N은 classes)

10. 미리 학습된 weights를 다운받는다. ([https://pjreddie.com/media/files/darknet53.conv.74](https://pjreddie.com/media/files/darknet53.conv.74))

11. 파일을 x64로 옮긴후 

darknet.exe detector train data/obj.data yolo-obj.cfg darknet53.conv.74 입력 

12. 학습하는 횟수는 cfg의 max_batches의 값을 변경하여 조절할 수  있다. 

13. backup폴더에 저장된 weights파일을 이용하여 

darknet.exe detector test data/obj.data yolo-obj.cfg yolo-obj_last.weights  를 입력 하여 test진행 

### 수많은 사진을 boxing하기 전 컴퓨터에서 학습이 잘 진행되는지 qr코드를 이용하여 학습한 내용

![yolo%20customizing%20%E1%84%87%E1%85%A1%E1%86%BC%E1%84%87%E1%85%A5%E1%86%B8%20%E1%84%86%E1%85%B5%E1%86%BE%20%E1%84%8B%E1%85%A7%E1%86%AB%E1%84%89%E1%85%B3%E1%86%B8%201a29c746a5f94da6a22263e90c8692f1/chart_yolo-obj.png](yolo%20customizing%20%E1%84%87%E1%85%A1%E1%86%BC%E1%84%87%E1%85%A5%E1%86%B8%20%E1%84%86%E1%85%B5%E1%86%BE%20%E1%84%8B%E1%85%A7%E1%86%AB%E1%84%89%E1%85%B3%E1%86%B8%201a29c746a5f94da6a22263e90c8692f1/chart_yolo-obj.png)

![yolo%20customizing%20%E1%84%87%E1%85%A1%E1%86%BC%E1%84%87%E1%85%A5%E1%86%B8%20%E1%84%86%E1%85%B5%E1%86%BE%20%E1%84%8B%E1%85%A7%E1%86%AB%E1%84%89%E1%85%B3%E1%86%B8%201a29c746a5f94da6a22263e90c8692f1/2.jpg](yolo%20customizing%20%E1%84%87%E1%85%A1%E1%86%BC%E1%84%87%E1%85%A5%E1%86%B8%20%E1%84%86%E1%85%B5%E1%86%BE%20%E1%84%8B%E1%85%A7%E1%86%AB%E1%84%89%E1%85%B3%E1%86%B8%201a29c746a5f94da6a22263e90c8692f1/2.jpg)

###########################################################################################################################################################

feedback 
각도를 틀어서 test를 진행할 경우 학습이 잘 진행되지 않는점을 감안하여 학습을 시킬때 여러 옵션을 추가하여 학습을 시켜야 할 것 같다. 

앞으로의 진행방향 

최종적으로 사용할 가중치파일을 만들기 위해 시뮬레이터와 uc-win Load를 setting하여 영상을 만든후 가중치 파일 제작