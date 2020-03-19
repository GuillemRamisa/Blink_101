kernel UVmap : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessRandom, eEdgeClamped> src;    //input image
  Image<eWrite> dst;                               //output image
  
  local:
    float width;                                   //float value to store the width
    float height;                                  //float value to store the height
  
  void init() {
    width = src.bounds.x2;                         //function to find right edge
    height = src.bounds.y2;                        //function to find top edge
  }

  void process(int2 pos) {
    dst(0) = pos.x / width;                        //pixel position X divided by width
    dst(1) = pos.y / height;                       //pixel position Y divided by height
    dst(2) = 0.0f;
    dst(3) = 0.0f; 
  }
};