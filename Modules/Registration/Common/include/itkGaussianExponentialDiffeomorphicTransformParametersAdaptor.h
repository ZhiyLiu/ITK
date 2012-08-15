/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkGaussianExponentialDiffeomorphicTransformParametersAdaptor_h
#define __itkGaussianExponentialDiffeomorphicTransformParametersAdaptor_h

#include "itkGaussianSmoothingOnUpdateDisplacementFieldTransformParametersAdaptor.h"

namespace itk
{
/** \class GaussianExponentialDiffeomorphicTransformParametersAdaptor
 * \brief Helper class for multiresolution image registration
 *
 * \author Nick Tustison
 *
 * \ingroup ITKRegistrationCommon
 */
template<class TTransform>
class ITK_EXPORT GaussianExponentialDiffeomorphicTransformParametersAdaptor
: public GaussianSmoothingOnUpdateDisplacementFieldTransformParametersAdaptor<TTransform>
{
public:

  /** Standard class typedefs. */
  typedef GaussianExponentialDiffeomorphicTransformParametersAdaptor                               Self;
  typedef GaussianSmoothingOnUpdateDisplacementFieldTransformParametersAdaptor<TTransform>         Superclass;
  typedef SmartPointer<Self>                                                                       Pointer;
  typedef SmartPointer<const Self>                                                                 ConstPointer;

  /** New macro for creation of through a Smart Pointer. */
  itkNewMacro( Self );

  /** Run-time type information (and related methods). */
  itkTypeMacro( GaussianExponentialDiffeomorphicTransformParametersAdaptor,
    GaussianSmoothingOnUpdateDisplacementFieldTransformParametersAdaptor );

  typedef TTransform                               TransformType;
  typedef typename TransformType::ScalarType       ScalarType;

  /**
   * Get/Set the Gaussian smoothing standard deviation for the velocity field.
   */
  virtual void SetGaussianSmoothingVarianceForTheVelocityField( ScalarType );
  itkGetConstReferenceMacro( GaussianSmoothingVarianceForTheVelocityField, ScalarType );

protected:
  GaussianExponentialDiffeomorphicTransformParametersAdaptor();
  ~GaussianExponentialDiffeomorphicTransformParametersAdaptor();

  void PrintSelf( std::ostream & os, Indent indent ) const;

private:
  GaussianExponentialDiffeomorphicTransformParametersAdaptor( const Self & ); //purposely not implemented
  void operator=( const Self & );             //purposely not implemented

  ScalarType          m_GaussianSmoothingVarianceForTheVelocityField;

  unsigned long       m_GaussianSmoothingVarianceForTheVelocityFieldSetTime;

}; //class GaussianExponentialDiffeomorphicTransformParametersAdaptor
}  // namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkGaussianExponentialDiffeomorphicTransformParametersAdaptor.hxx"
#endif

#endif /* __itkGaussianExponentialDiffeomorphicTransformParametersAdaptor_h */