# Aruco Marker 생성하기!

```cpp
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>

using namespace cv;
using namespace std;

int main()
{

	cv::Mat markerImage;
	cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
	cv::aruco::drawMarker(dictionary, 22, 200, markerImage, 1);
	cv::imwrite("marker22.png", markerImage);

}
```

#include <opencv2/opencv.hpp>

*opencv를 사용하겠음!

#include <opencv2/aruco.hpp>

*opencv의 추가 라이브러리인 aruco를 사용하겠음!

cv::Mat markerImage;

*markerimage라는 행렬을 선언

cv::Ptr[cv::aruco::Dictionary](cv::aruco::Dictionary) dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

*aruco를 사용하기 위한 딕셔너리를 선언

cv::aruco::drawMarker(dictionary, 22, 200, markerImage, 1);
cv::imwrite("marker22.png", markerImage);

*사이즈가 200*200고 id가 22인 마커를 1개 생성한다는 코드*

프로젝트에서 오른쪽 마우스 클릭하여 확인!

![Aruco%20Marker%20%E1%84%89%E1%85%A2%E1%86%BC%E1%84%89%E1%85%A5%E1%86%BC%E1%84%92%E1%85%A1%E1%84%80%E1%85%B5!%20d2b3eae362b04c8ab1340af3d9331f9e/Untitled.png](Aruco%20Marker%20%E1%84%89%E1%85%A2%E1%86%BC%E1%84%89%E1%85%A5%E1%86%BC%E1%84%92%E1%85%A1%E1%84%80%E1%85%B5!%20d2b3eae362b04c8ab1340af3d9331f9e/Untitled.png)

비주얼스튜디오2019의 c++환경에서 위의 코드를 돌리면 프로젝트 폴더에 아래와 같이 생성된다.

![Aruco%20Marker%20%E1%84%89%E1%85%A2%E1%86%BC%E1%84%89%E1%85%A5%E1%86%BC%E1%84%92%E1%85%A1%E1%84%80%E1%85%B5!%20d2b3eae362b04c8ab1340af3d9331f9e/Untitled%201.png](Aruco%20Marker%20%E1%84%89%E1%85%A2%E1%86%BC%E1%84%89%E1%85%A5%E1%86%BC%E1%84%92%E1%85%A1%E1%84%80%E1%85%B5!%20d2b3eae362b04c8ab1340af3d9331f9e/Untitled%201.png)

위의 코드를 인쇄하여 모니터화면의 적당한 위치에 붙여 코드를 완성시키자!