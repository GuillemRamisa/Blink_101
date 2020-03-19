kernel Custom_ColorSwitch : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessPoint,eEdgeClamped> src;                       //input image with edges clamped 
  Image<eWrite> dst;                                                //output image
  
  param:
    bool Switch;                                                    //switch parameter
    float4 color;                                                   //color parameter
  
  void define() {
    defineParam(Switch,"Switch", true);                             //default value
    defineParam(color, "Custom color", float4(0.0f,1.0f,0.0f,0.0f));//default value
  }
  
  void process() {
    dst() = Switch == true ? src() : color;                         //conditional 
  }
};