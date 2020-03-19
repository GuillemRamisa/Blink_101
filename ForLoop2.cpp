kernel For_Loop2 : ImageComputationKernel <ePixelWise>
{
  Image<eRead,eAccessRandom,eEdgeClamped> src;                        //input image
  Image<eWrite> dst;                                                  //output image

  param:
    int trigger;
    int increments;                                                   //increment param
    int amount;                                                       //amount param

  void define(){
    defineParam(trigger,"trigger",10);                                //loop trigger
    defineParam(increments,"increments", 2);                          //increment default
    defineParam(amount,"amount",100);                                 //amount default
  }

  void process(int2 pos) {
    int total = 0;                                                    //total initial value

    for (int i = trigger; i =< increments; i++) {                     //loop
      total += amount;                                                //loop sum
    }

    dst() = src((pos.x+total),pos.y);                                 //out
  }
};