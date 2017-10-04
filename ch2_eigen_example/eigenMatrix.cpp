#include <iostream>
#include <ctime>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>

#define MATRIX_SIZE 50

int main(int argc, char** argv){
  Eigen::Matrix<float, 2, 3> matrix_23;
  Eigen::Vector3d v_3d;
  Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();

  matrix_23 << 0, 1, 2, 3, 4, 5;
  cout << matrix_33 << endl;
  cout << matrix_23 << endl;

  for( int i = 0; i < 1; ++i)
  	for( int j = 0; j < 2; ++j)
  		cout << matrix_23(i,j) << endl;

  v_3d << 1, 2, 3;
  Eigen::Vector2d result = matrix_23.cast<double>() * v_3d;

  cout << result << endl;


  matrix_33 = Eigen::Matrix3d::Random();
  cout << matrix_33 << endl << endl;

  cout << matrix_33.transpose() << endl;
  cout << matrix_33.trace() << endl;
  cout << matrix_33.inverse() << endl;
  cout << matrix_33.determinant() << endl;

  Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver (matrix_33.transpose() * matrix_33);
  cout << "Eigen values = " << eigen_solver.eigenvalues() << endl;
  cout << "Eigen vectors = " << eigen_solver.eigenvectors() << endl;

  Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
  matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
  Eigen::Matrix<double, MATRIX_SIZE, 1> v_N;
  v_N = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);

  clock_t time_start = clock();
  Eigen::Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse()*v_N;
  cout << "time use in normal inverse is " << 1000.*(clock() - time_start)
  											  / (double) CLOCKS_PER_SEC << "ms"
  										   << endl;

  time_start = clock();
  x = matrix_NN.colPivHouseholderQr().solve(v_N);
  cout << "time use in QR decomposition is " << 1000.*(clock() - time_start)
  											  / (double) CLOCKS_PER_SEC << "ms"
  										     << endl;

  return 0;


}