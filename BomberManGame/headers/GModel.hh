//
// GModel.hh for cpp_bomberman in /home/ovoyan_s/rendu/cpp_bomberman/client_graphique
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed May 28 19:16:50 2014 ovoyan_s
// Last update Fri Jun 13 20:10:49 2014 ovoyan_s
//

#ifndef				GMODEL_HH_
# define			GMODEL_HH_

/*
**				GDL INCLUDES
*/

# include			<AShader.hh>
# include			<glm/gtc/matrix_transform.hpp>
# include			<Model.hh>
# include			<vector>

/*
**				MY INCLUDES
*/

# include			"Entity.hh"
# include			"Containers.hpp"
# include			"GraphParsing.hh"
# include			"Number.hpp"

class				GModel
{
protected:
  glm::mat4			*transMatrix;
  float				coordX;
  float				coordY;
  float				coordZ;
  float				scale;
  Number<float>			angleOfRotationX;
  Number<float>			angleOfRotationY;
  Number<float>			angleOfRotationZ;
  bool				isClimb;
  EntityNS::Nature		typeOfModel;
  float				size;
  int				coordMapX;
  int				coordMapY;
  bool				toShow;

  GModel();

public:
  GModel(float scaleToSet, const Point3D<float> &coordinates, const EntityNS::Nature &typeToSet);
  void				Draw(gdl::AShader *shader, double clockTime,
				     gdl::Model *objectModel);

  void				setLoaderChars1();
  void				setLoaderChars2();
  void				setLoaderSpecials();

  //				Matrix Rotation And Complex Transformations

  void                          RotationX(float rotationAngle);
  void                          RotationY(float rotationAngle);
  void                          RotationZ(float rotationAngle);
  void                          RotationSelfX(float rotationAngle);
  void                          RotationSelfY(float rotationAngle);
  void                          RotationSelfZ(float rotationAngle);
  void				itemMove(float lowPoint, float HighPoint);
  void				minecraftMove(float lowPoint, float HighPoint);

  //				Setters

  void				setCoordX(float coordToSetX);
  void				setCoordY(float coordToSetY);
  void				setCoordZ(float coordToSetZ);
  void				setModelType(const EntityNS::Nature &modelType);
  void				setTransformation(const glm::mat4 &matrixToUse);
  void				setCoordMapX(int coordX);
  void				setCoordMapY(int coordY);
  void				setShow(bool showToSet);

  //				Getters

  float				getCoordX() const;
  float				getCoordY() const;
  float				getCoordZ() const;
  EntityNS::Nature		getModelType() const;
  glm::mat4			getTransformation() const;
  int				getCoordMapX() const;
  int				getCoordMapY() const;
  bool				getShow() const;

  ~GModel();
};

#endif				/*	GMODEL_HH_	*/
