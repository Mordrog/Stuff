#include <osg/AnimationPath>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>


#include <osg/Geode>
#include <osg/ShapeDrawable>

using osg::Box;
using osg::Geode;
using osg::Node;
using osg::ShapeDrawable;
using osg::Sphere;
using osg::Vec3;
using osg::Vec4;
using osgViewer::Viewer;
Node * ball(float R, float B, float G, float Radius)
{
    Geode * geom_node = new Geode();

    ShapeDrawable * drw = new ShapeDrawable();
    drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(0.0, 0.0, 0.0), Radius));
    drw->setColor(Vec4(R, G, B, 1.0));
    geom_node->addDrawable(drw);

    return geom_node;
}


osg::AnimationPath* createAnimationPath( float X, float Y, float Z, float time)
{
	osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
	path->setLoopMode( osg::AnimationPath::LOOP );
	unsigned int numSamples = 32;
	float delta_time = time / (float)numSamples;
	for ( unsigned int i=0; i<numSamples; ++i )
	{
		osg::Vec3 pos( i*X ,i*Y, i*Z );
		osg::Quat rot( 0, osg::Z_AXIS );
		path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
	}
	return path.release();
}

class ModelController : public osgGA::GUIEventHandler
{
public:
	ModelController( osg::MatrixTransform* node )
	: _model(node)
{}
virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa );
protected:
	osg::ref_ptr<osg::MatrixTransform> _model;
};


bool ModelController::handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa )
{
	if ( !_model ) return false;
	osg::Matrix matrix = _model->getMatrix();
	switch ( ea.getEventType() )
	{
	case osgGA::GUIEventAdapter::KEYDOWN:
		switch ( ea.getKey() )
		{
		case 'a': case 'A':
			matrix *= osg::Matrix::rotate(-0.1f, osg::Z_AXIS);
			break;
		case 'd': case 'D':
			matrix *= osg::Matrix::rotate(0.1f, osg::Z_AXIS);
			break;
		case 'w': case 'W':
			matrix *= osg::Matrix::rotate(-0.1f, osg::X_AXIS);
			break;
		case 's': case 'S':
			matrix *= osg::Matrix::rotate(0.1f, osg::X_AXIS);
			break;
		default:
			break;
		}
		_model->setMatrix( matrix );
		break;
	default:
		break;
	}
	return false;
}





int main(){
	osg::ref_ptr<osg::Node> modelX = ball(1,0,0,1);
	osg::ref_ptr<osg::Node> modelY = ball(0,1,0,1);
	osg::ref_ptr<osg::Node> modelZ = ball(0,0,1,1);
	osg::ref_ptr<osg::MatrixTransform> MatrixX = new osg::MatrixTransform;
	osg::ref_ptr<osg::MatrixTransform> MatrixY = new osg::MatrixTransform;
	osg::ref_ptr<osg::MatrixTransform> MatrixZ = new osg::MatrixTransform;
	MatrixX->addChild( modelX.get() );
	MatrixY->addChild( modelY.get() );
	MatrixZ->addChild( modelZ.get() );
	osg::ref_ptr<osg::AnimationPathCallback> apcbX = new osg::AnimationPathCallback;
	apcbX->setAnimationPath( createAnimationPath(1.0f,0.0f,0.0f, 6.0f) );

	osg::ref_ptr<osg::AnimationPathCallback> apcbY = new osg::AnimationPathCallback;
	apcbY->setAnimationPath( createAnimationPath(0.0f,1.0f,0.0f, 6.0f) );
	
	osg::ref_ptr<osg::AnimationPathCallback> apcbZ = new osg::AnimationPathCallback;
	apcbZ->setAnimationPath( createAnimationPath(0.0f,0.0f,1.0f, 6.0f) );

	MatrixX->setUpdateCallback( apcbX.get() );
	MatrixY->setUpdateCallback( apcbY.get() );
	MatrixZ->setUpdateCallback( apcbZ.get() );

	osg::ref_ptr<osg::MatrixTransform> root = new osg::MatrixTransform;

	root->addChild( MatrixX.get() );
	root->addChild( MatrixY.get() );
	root->addChild( MatrixZ.get() );

	osg::ref_ptr<ModelController> ctrler = new ModelController( root.get() );


	osgViewer::Viewer viewer;
	viewer.addEventHandler( ctrler.get() );
	viewer.getCamera()->setViewMatrixAsLookAt(osg::Vec3(0.0f,-100.0f,0.0f), osg::Vec3(), osg::Z_AXIS );
	viewer.getCamera()->setAllowEventFocus( false );

	viewer.setSceneData( root.get() );
	viewer.setUpViewInWindow(500, 500, 1000, 500);
	return viewer.run();
}


