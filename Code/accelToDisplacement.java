public double[][][] accelToDistance(double[][][] inputVal, double t) {
  log(INFO);

  double[][][] returnVal = new double[inputVal.length][NUM_AXIS][inputVal[0][0].length];

  for (int time = 0; time < inputVal.length; time++)
    for (int axis = 0; axis < NUM_AXIS; axis++)
      for (int item = 0; item < inputVal[time][axis].length; item++)
        returnVal[time][axis][item] = (inputVal[time][axis][item] * t * t) / 2;

  return returnVal;
}
