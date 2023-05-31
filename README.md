# FdF
## Resources
- https://behreajj.medium.com/3d-rotations-in-processing-vectors-matrices-quaternions-10e2fed5f0a3
- https://www.engr.uvic.ca/~mech410/lectures/4_2_RotateArbi.pdf
- http://www.cse.iitm.ac.in/~vplab/courses/CV_DIP/PDF/GEOM+PROJ+STEREO.pdf
- http://www.cse.iitm.ac.in/~vplab/courses/CG/PDF/TRANS_2D.pdf There is trans_3D also just try and change the links.


## How to install X11 library
- sudo apt-get install libxext-dev
- sudo apt-get install libx11-dev


## How to run a libft function with main inside it
- cd libft && make
- gcc dlst/ft_dlstadd_back.c -I includes 
- ./a.out

## Quarternion notes
```
i^2 = j^2 = k^2 = ijk = -1
ij = k
ji = -k
jk = i
kj = -i
ki = j
ik = -j
```
- Represent the point as a quaternion: Convert the 3D point (x, y, z) into quaternion form by setting the scalar (real) part to zero and the vector (imaginary) part to the coordinates of the point. For example, if the point is P(x, y, z), its quaternion representation would be p = 0 + xi + yj + zk.
- if you want to rotate a point by an angle θ around the x-axis, you can use the quaternion rotation
```
q = cos(θ/2) + sin(θ/2) * i
```
- if you want to rotate a point by an angle θ around the y-axis, you can use the quaternion rotation
```
q = cos(θ/2) + sin(θ/2) * j
```
- p_rotated = q * p * q_inverse
- p_rotated around x-axis= (cos(θ/2) + sin(θ/2) * i) * (0 + xi + yj + zk) * (cos(θ/2) - sin(θ/2) * i)
- p_rotated around y-axis= (cos(θ/2) + sin(θ/2) * j) * (0 + xi + yj + zk) * (cos(θ/2) - sin(θ/2) * j)
- p_rotated around z-axis= (cos(θ/2) + sin(θ/2) * k) * (0 + xi + yj + zk) * (cos(θ/2) - sin(θ/2) * k)
- p_rotated around x-axis = x1i + ((a * a - b * b) * y1 - (2 * a * b) * z1)j + ((2 * a * b) * y1 + (a * a - b * b) * z1)k where a = cos(θ/2) and b = sin(θ/2)
- p_rotated around y-axis = ((a * a - b * b) * x1 + (2 * a * b) * z1)i + y1j + ((-2 * a * b) * x1 + (a * a - b * b) * z1)k where a = cos(θ/2) and b = sin(θ/2)
- p_rotated around z-axis = ((a * a - b * b) * x1 - (2 * a * b) * y1)i + ((2 * a * b) * x1 + (a * a - b * b) * y1)j + z1k where a = cos(θ/2) and b = sin(θ/2) // not sure about this one


