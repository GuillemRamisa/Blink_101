kernel Custom_Color : ImageComputationKernel<ePixelWise>
{
  Image<eWrite> dst;                                                      //output image
  
  param:
    float4 color;                                                         //parameter
  
  void define() {
    defineParam(color, "Custom color", float4(0.0f,1.0f,0.0f,0.0f));      //defalut value
  }
  
  void process() {
    dst() = color;                                                        //output
  }
};