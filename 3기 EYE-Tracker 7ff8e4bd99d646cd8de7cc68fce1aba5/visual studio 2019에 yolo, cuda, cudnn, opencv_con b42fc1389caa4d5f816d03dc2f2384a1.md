# visual studio 2019에 yolo, cuda, cudnn, opencv_contrib 적용하기

opencv_contrib부터 적용하는 방법이다.

1. opencv를 윈도우즈 환경에서 비주얼 스튜디오에서 사용하도록 빌드하는 방법은 대부분 비슷하다.(그리고 쉽다.)

몇가지 차이점이 있을 뿐인데, 처음이라면, 일단 아래의 과정을 있는 그대로 따라해보고 어떻게 하는 건지, 스스로 한번 해보고 돌려보는 것이 좋다.

1. 

[https://opencv.org/releases/](https://opencv.org/releases/)

[https://github.com/opencv/opencv_contrib](https://github.com/opencv/opencv_contrib)

[https://cmake.org](https://cmake.org/)

위의 링크에서 각각 설치 파일을 다운로드 받는다.

(내 기준으론 opencv 411, opencv_contrib 411, cmake 3145)

CMake는 설치 파일을 다운받으면 되고,

OpenCV는 git 페이지로 들어가, Release 태그 안에 있는 SourceCode.zip 파일을 다운받고,

OpenCV_contrib도 역시 git 페이지에서 Release 된 zip 파일을 받으면 된다.

(contrib는 OpenCV의 추가 모듈로, 기본 OpenCV보다 더 많은 역할을 하는 추가 라이브러리라 생각하자.)

1. cmake를 설치해준다.
2. OpenCV 시리즈의 압축을 풀고,

OpenCV411_Source라는 폴더 안에 넣은 후, 간단하게 C드라이버로 이동시키자.

1. cmake GUI를 실행시키고,

where is the source code 항목에는, 아까 OpenCV411_Source 폴더 안에 넣은 OpenCV411 폴더의 위치, 그러니까, CMakeLists.txt가 있는 폴더를 선택해준다.

where to build the binaries 항목에는, 해당 OpenCV를 CMake로 빌드해서 어디로 옮길지를 정해준다.

간단하게, C:/OpenCV411_Build라고 적어주거나 다르게 적어도 된다.

1. 좌측 하단의 Configure 버튼을 누른다.

그리고 빌드 환경으론, visual studio 16 2019를 선택하고 그대로 finish.

1. 조금 기다리면 빨간색 설정들이 보인다.

에러난게 아니다.

아래 콘솔창에 configuring done이 뜨면 된다.

Search 창에,

tests를 검색하고, test 항목들을 체크 해제.

extra를 검색하고, opencv extra module path에 아까 압축 풀어두었던 추가 모듈 위치를 적어주면 된다.

위치는 대략 c:/OpenCV411_Source/opencv_contrib-4.1.1/modules로, contrib 폴더 안의 modules 폴더를 지정하면 된다.

nonfredd를 검색하고, opencv_enable_nonfree를 체크.

install을 검색하고, cmake_install_prefix 항목에, 빌드한 파일들이 최종 저장될 곳을 설정해준다.

디폴트로는, 아까 설정한 OpenCV411_Build 폴더 안의 install 폴더.

그대로 쓰거나, 따로 옮겨주고 싶은 사람들은 원하는 곳으로 설정하면 된다.

여기까지가 빌드를 어떻게 할것인지를 설정한 것이고,

이제부터 빌드시 쓸데없는 빌드를 줄이는 과정이다.

build를 검색하고,

아래의 요소들을 체크 해제한다.

Build_JAVA

Build_Package

with를 검색하고,

아래의 요소들을 체크 해제한다.

with_1394

with_gstreamer

with_lapack

with_vtk

여기까지 하고 Configure을 한다.

그리고 Configuring done이 되면,

다시 Search 창에,

world라고 검색하고,

build_opencv_world를 체크한다.

이 옵션은 opencv 모든 모듈을 통합하는 world를 만들어 visual studio에 편하게 적용하게 해주는 역할을 한다.

또, 변경된 옵션을 적용하기 위해 Configure 버튼을 누르고,

이제는 설정이 완료되었으니 Generate 버튼을 누르면 된다.

이제 cmake 빌드는 완료된 것인데,

이것을 visual studio를 이용하여 다시한번 빌드를 해줘야 끝이난다.

1. cmake gui 하단 버튼중 활성화된 open project를 누른다.

visual studio가 실행되며, 이제까지 빌드했던 프로젝트가 실행된다.

켜진 visual studio의 모드를 release x64로 하여, 프로젝트 탐색창에서 cmaketargets폴더 안의 install 프로젝트를 우클릭하여 빌드를 눌러 빌드한다.

그리고 이후 debug x64로 하여 다시한번 빌드를 한다.

꽤 시간이 걸릴텐데,

기다리면,

아까 설정한 빌드 install 폴더가 생성되며, 그 안에 빌드한 정보가 담기게 된다.

디폴트는 OpenCV411_Build 폴더 안의 install 폴더, 따로 설정한 사람은, 해당 설정의 위치로 가면 볼수있다.

이제 이 install 폴더 안의 요소들을 include 하여 visual studio의 프로젝트를 진행할수 있다.

- ***VISUAL STUDIO 2019에서 OPENCV 설정하기**

c/c++ 일반 추가포함 라이브러리:C:\source\install\include

링커-추가라이브러리:C:\source\install\x64\vc16\lib

구성속성의 디버깅-환경: PATH=C:\source\install\x64\vc16\bin;%PATH%

그리고 release나 debug 모드에 따라서 사용할 라이브러리를 구분하기 위하여,

설정의 구성을 먼저 debug로 바꾸고,

링커 - 입력의 추가 종속성 항목 가장 앞에,

lib폴더 안의 라이브러리를 추가해준다.

아까 빌드할때, 모든 모듈을 통합한 world를 빌드했으니, 해당 world 라이브러리만 추가하면 간편하다.

(ex : opencv_world411d.lib;)

똑같이 설정의 구성을 release로 해주고,

링커 - 입력의 추가 종속성 항목 가장 앞에,

lib폴더 안의 라이브러리를 추가해준다.

(ex : opencv_world411.lib;)

1. 이로써 해당 프로젝트는 opencv를 사용할 준비가 된 것이다.

이제 한번 시험을 해보자.

열려있는 console 코드 안의 모든 텍스트를 지우고,

c:/OpenCV411_Source/OpenCV411/samples/cpp

안의 videocapture_basic.cpp를 텍스트 편집기로 열어서,

해당 코드를 복사한 후,

그대로 내가 OpenCV를 연결시킨 프로젝트 안에 붙여넣는다.

그리고 실행하면,

카메라 화면이 opencv 라이브러리를 사용하여 잘 나타내지게 되는 것이다.

//팁 : 만약 OpenCV bin 디렉토리를 윈도우 시스템 환경변수에 설정했다면...

예를들어 OpenCV_DIR이란 이름으로 저장 후, path에 %OpenCV_DIR%\bin; 이렇게 등록했다면,

해당 opencv를 cmd에서 그냥 사용할수 있고,

또한 VS에서 $(OpenCV_DIR)\include 이런 식으로 경로 설정이 가능하다.

---

이후에 이렇게 빌드하는 방법을 알았으므로 위에서 언급한 visual studio에 yolo,cuda,cudnn에 일반적이 opencv대신에 opencv_contrib를 연결하면 된다.