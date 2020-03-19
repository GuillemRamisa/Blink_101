kernel UVmap2 : ImageComputationKernel<ePixelWise>
{
  Image<eWrite> dst;                      //output image
  
  param:
    float width;                          //float value to store the width
    float height;                         //float value to store the height
  
  void define() {
    defineParam(width,"width",256.0f);    //width custom param
    defineParam(height,"height",256.0f);  //height custom param
    }

  void process(int2 pos) {
    dst(0) = pos.x / width;               //pixel position X divided by width
    dst(1) = pos.y / height;              //pixel position Y divided by height
    dst(2) = 0.0f;                        //blue channel as 0.0f
    dst(3) = 0.0f;                        //alpha channel as 0.0f
  }
};