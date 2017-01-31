public double[][][] LowpassFilter(double[][][] data, String sensorName, String userName) {
  log(INFO);

  DoubleFFT_1D realfft = new DoubleFFT_1D(data[0][0].length);

  // Execute forward fourier transform
  for (double[][] i : data) for (double[] j : i) realfft.realForward(j);

  // Low pass filtering
  for (int time = 0; time < data.length; time++)
    for (int axis = 0; axis < NUM_AXIS; axis++)
      for (int item = 0; item < data[time][axis].length; item++)
        if (item > 30) data[time][axis][item] = 0;

  // Execute inverse fourier transform
  for (double[][] i : data) for (double[] j : i) realfft.realInverse(j, true);

  return data;
}
