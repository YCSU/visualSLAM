#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>


int main(int argc, char** argv){

  Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
  Eigen::AngleAxisd rotation_vector( M_PI/4, Eigen::Vector3d(0,0,1) );
  cout.precision(3);
  cout << "rotation matrix = \n" << rotation_vector.matrix() << endl;

  rotation_matrix = rotation_vector.toRotationMatrix();
  cout << "rotation matrix = \n" << rotation_matrix << endl;

  Eigen::Vector3d v(1,0,0);
  Eigen::Vector3d v_rotated = rotation_vector * v;
  cout << "(1, 0, 0) after rotation = \n " << v_rotated << endl;

  v_rotated = rotation_matrix * v;
  cout << "(1, 0, 0) after rotation = \n " << v_rotated << endl;

  Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);
  cout << "yaw pitch roll = \n" << euler_angles << endl;
  
  Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
  T.rotate( rotation_vector );
  T.pretranslate( Eigen::Vector3d(1, 3, 4) );
  cout << "transform matrix = \n" << T.matrix() << endl;

  Eigen::Vector3d v_transformed = T * v;
  cout << "v transformec = \n" << v_transformed << endl;

  Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
  cout << "quaternion = \n" << q.coeffs() << endl;
  v_rotated = q * v;
  cout << "(1, 0, 0) after rotation = \n" << v_rotated << endl;

  return 0;

}