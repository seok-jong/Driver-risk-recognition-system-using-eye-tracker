# darknet에 qr코드를 적용한 코드

darknet의 솔루션에 들어가서 image_opencv.cpp에 들어가서 1000번째 줄을 확인하자!

cv::Ptr[cv::aruco::Dictionary](cv::aruco::Dictionary) dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250); 

*aruco를 사용하기 위해 딕셔너리 코드를 작성한다.

int ak47 = 0;

*타임스탬프를 찍기 위한 변수 선언!

```jsx
Point2f inputQuad[4];
Point2f outputQuad[4];
Mat input, output;
```

*inputQuad와 outputQuad는 qr코드의 좌표를 얻기 위한 포인트변수이다!

```jsx
std::vector<int> ids;
std::vector<std::vector[cv::Point2f](cv::Point2f) > corners;
```

*각 qr코드의 좌표의 ids, corners들을 담기 위한 벡터 선언

```jsx
cv::aruco::detectMarkers(*show_img, dictionary, corners, ids);
if (ids.size() > 0)
cv::aruco::drawDetectedMarkers(*show_img, corners, ids);
```

*qr코드를 detecting하는 aruco의 코드 이것은 필수!

```jsx
int s = ids.size();
```

*발견된 아이디들의 사이즈를 담는 변수 s (*qr코드의 개수가 저장된다.)

```jsx
cv::Point2i top_left, top_right, bot_left, bot_right;
cv::Point2i nullQR(0, 0);
cv::Point2f gPoint(myint1, myint2);
```

*top_left,top_right,bot_left,bot_right가 담디는 포인트 변수와, 아무qr코드도 발견되지 않았을 때, 담겨지는 좌표(0,0),  myint1(x)와 myint2(y)는 gpoint에 담긴다.

```jsx
for (int i = 0; i < ids.size(); i++) {
if (ids[i] == 19) { cv::Point2f temp(corners[i][0].x, corners[i][0].y); top_left = temp; }
else if (ids[i] == 20) { cv::Point2f temp(corners[i][0].x, corners[i][0].y); top_right = temp; }
else if (ids[i] == 21) { cv::Point2f temp(corners[i][0].x, corners[i][0].y); bot_left = temp; }
else if (ids[i] == 22) { cv::Point2f temp(corners[i][0].x, corners[i][0].y); bot_right = temp; }
```

```
else if (ids[i] == 23) { cv::Point2f temp(corners[i][0].x, corners[i][0].y); top_left = temp; }
else if (ids[i] == 24) { cv::Point2f temp(corners[i][1].x, corners[i][1].y); top_right = temp;}
else if (ids[i] == 25) { cv::Point2f temp(corners[i][3].x, corners[i][3].y); bot_left = temp;}
 else if (ids[i] == 26) { cv::Point2f temp(corners[i][2].x, corners[i][2].y); bot_right = temp;}

else if (ids[i] == 27) { cv::Point2f temp(corners[i][2].x, corners[i][2].y); top_left = temp; }
else if (ids[i] == 28) { cv::Point2f temp(corners[i][2].x, corners[i][2].y); top_right = temp; }
else if (ids[i] == 29) { cv::Point2f temp(corners[i][2].x, corners[i][2].y); bot_left = temp; }
else if (ids[i] == 30) { cv::Point2f temp(corners[i][2].x, corners[i][2].y); bot_right = temp; }
```

*발견된 qr코드의 좌표들이 for문이 돌아가면서 저장된다.

```jsx
inputQuad[0] = top_left;//왼쪽위
inputQuad[1] = top_right;//오른쪽위
inputQuad[2] = bot_right;//오른쪽아래
inputQuad[3] = bot_left;//왼쪽아래
outputQuad[0] = Point2f(0, 0);
outputQuad[1] = Point2f(input.cols - 1, 0);
outputQuad[2] = Point2f(input.cols - 1, input.rows - 1);
outputQuad[3] = Point2f(0, input.rows - 1);
```

*top_left,top_right,bot_right,bot_left가 두 변수에 저장된다.

```jsx
Mat lambda = getPerspectiveTransform(inputQuad, outputQuad);
warpPerspective(input, output, lambda, output.size());
```

*화면상에서 왜곡되어 보이는 화면을 2차원의 평면으로 보여주는 코드(perspective transform)을 사용하여 투영한다.