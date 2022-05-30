# eye-tracker-5주차

## 저희가 이번 프로젝트에 진행해야 할 목표는 크게 봤을 때 2가지 정도 됩니다.

### 1.아이트래커- 터미네이터가 세상을 보는 것처럼 아이트래커로 물체의 정보 얻기입니다.

### a) 아이트래커에서 영상을 받습니다.

![eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/data_109.jpg](eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/data_109.jpg)

### b) 영상을 받아 오는 동시에 ts(time_stamp)와 gp(gaze_point)를 얻어 옵니다.

![eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/_-_.png](eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/_-_.png)

### c) 이렇게 받아 온 데이터의 전처리를 실행합니다.

![eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/Untitled.png](eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/Untitled.png)

### d) yolo를 이용하여 얻어온 데이터에서 물체를 인식하여 사각형을 그립니다.

![eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d.png](eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d.png)

### e) keras를 이용하여 딥러닝을 해서 모델을 생성합니다.

### f) 이런 방법으로 진행한다면 터미네이터가 바라보는 세상을 만들 수 있을 것입니다.

![eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d.jpg](eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d.jpg)

## 2-헤드 트래커

### a) 헤드 트래커를 이용하여 물체와의 거리를 알아내는 작업을 합니다.

헤드 트래커의 API를 이용하여 Z축을 보고 거리를 대략적으로 측정합니다.

+정확하지 않을 수 있기 때문에 여러 번의 시행을 하여 대략적인 평균 값을 얻습니다.

![eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/Untitled%201.png](eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/Untitled%201.png)

## 3-아이 트래커와 헤드 트래커

### 아이 트래커와 헤드 트래커의 좌표계를 서로 연결시켜주는 작업을 합니다.

### 또한, 앞의 작업이 끝난 아이 트래커와 카메라의 좌표계를 각각 연결시킵니다.

![eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/Untitled%202.png](eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/Untitled%202.png)

### CAD/CAM/CAE 시스템이라는 책을 이용하여 매핑을 공부합니다.

![eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/Untitled%203.png](eye-tracker-5%E1%84%8C%E1%85%AE%E1%84%8E%E1%85%A1%20e3b745c5e627404687aec7d581ca8f1d/Untitled%203.png)