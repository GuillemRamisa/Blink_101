kernel SimpleKernel : ImageComputationKernel<ePixelWise>
{
  Image<eRead, eAccessPoint> src;
  Image<eWrite> dst;
  
  param:
  
  local: 
  
  void define() {
  }
  
  void init() {
  }
  
  void process() {
    dst() = src();
  }
};