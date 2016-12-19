#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/AnimationPath>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventHandler>//do kontrolera
#include <osgViewer/Viewer>


using osg::CopyOp;
using osg::Geode;
using osg::Node;
using osg::ShapeDrawable;
using osg::Sphere;
using osg::Vec3;
using osg::Vec4;
using osgViewer::Viewer;

float AU = 1495.97887;// Astronomical Unit
float PS = 12.756;// Planet Size
float Year = 365.2563;

osg::ref_ptr<osg::MatrixTransform> root = new osg::MatrixTransform;

void modelMercury(Geode * planet){
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(AU*0.3871,0.0, 0), 0.3825*PS));
    drw->setColor(Vec4(1.0, 0.9, 0.6, 1.0));
    planet->addDrawable(drw);
}



void CreatePlanet(){
Geode * planet = new Geode();
    modelMercury(planet);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radius = 50;
    float time = 60;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radius, cosf(yaw)*radius, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}

void Sun(){
Geode * planet = new Geode();
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(0.0,0.0, 0), 109));
    drw->setColor(Vec4(1.0, 1.0, 0.0, 1.0));
    planet->addDrawable(drw);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radius = 50;
    float time = 60;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radius, cosf(yaw)*radius, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}


void Mercury(){
Geode * planet = new Geode();
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(AU*0.3871,0.0, 0), 0.3825*PS));
    drw->setColor(Vec4(1.0, 0.9, 0.6, 1.0));
    planet->addDrawable(drw);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radiusX = AU*0.3871;
    float radiusY = AU*0.3788;
    float time = Year*0.2408;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radiusX, cosf(yaw)*radiusY, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}

void Venus(){
Geode * planet = new Geode();
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(AU*0.7233,0.0, 0), 0.9489*PS));
    drw->setColor(Vec4(1.0, 0.5, 0.0, 1.0));
    planet->addDrawable(drw);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radiusX = AU*0.7233;
    float radiusY = AU*0.7233;
    float time = Year*0.6152;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radiusX , cosf(yaw)*radiusY, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}

void Earth(){
Geode * planet = new Geode();
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(AU,0,0), 1.0*PS));
    drw->setColor(Vec4(0.5, 1.0, 1.0, 1.0));
    planet->addDrawable(drw);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radiusX = AU*1.000;
    float radiusY = AU*0.9998;
    float time = Year;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radiusX, cosf(yaw)*radiusY, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}

void Mars(){
Geode * planet = new Geode();
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(AU*1.5237,0.0, 0), 0.5335*PS));
    drw->setColor(Vec4(0.7, 0.0, 0.0, 1.0));
    planet->addDrawable(drw);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radiusX = AU*1.5236;
    float radiusY = AU*1.5170;
    float time = Year*1.8808;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radiusX, cosf(yaw)*radiusY, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}

void Jupiter(){
Geode * planet = new Geode();
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(AU*5.2034,0.0, 0), 11.2092*PS));
    drw->setColor(Vec4(1, 0.9, 0.9, 1.0));
    planet->addDrawable(drw);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radiusX = AU*1.5236;
    float radiusY = AU*1.5170;
    float time = Year*11.8637;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radiusX, cosf(yaw)*radiusY, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}

void Saturn(){
Geode * planet = new Geode();
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(AU*9.5372,0.0, 0.0), 9.4494*PS));
    drw->setColor(Vec4(1, 0.7, 0.4, 1.0));
    planet->addDrawable(drw);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radiusX = AU*1.5236;
    float radiusY = AU*1.5170;
    float time = Year*29.4484;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radiusX, cosf(yaw)*radiusY, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}

void Uran(){
Geode * planet = new Geode();
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(AU*19.1913,0.0, 0), 4.0074*PS));
    drw->setColor(Vec4(0.8, 1.0, 1.0, 1.0));
    planet->addDrawable(drw);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radiusX = AU*1.5236;
    float radiusY = AU*1.5170;
    float time = Year * 84.0711;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radiusX, cosf(yaw)*radiusY, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}

void Neptun(){
Geode * planet = new Geode();
    ShapeDrawable * drw = new ShapeDrawable();
    drw->setShape(new Sphere(Vec3(AU*30.0690,0.0, 0), 3.8827*PS));
    drw->setColor(Vec4(0.0, 0.5, 0.9, 1.0));
    planet->addDrawable(drw);

osg::ref_ptr<osg::MatrixTransform> transformMatrix = new osg::MatrixTransform;
    transformMatrix->addChild( planet );

osg::ref_ptr<osg::AnimationPathCallback> pathCallback = new osg::AnimationPathCallback;
osg::ref_ptr<osg::AnimationPath> path = new osg::AnimationPath;
    path->setLoopMode( osg::AnimationPath::LOOP );
    float radiusX = AU*1.5236;
    float radiusY = AU*1.5170;
    float time = Year * 164.8799;
    unsigned int numSamples = 32;
    float delta_yaw = 2.0f * osg::PI / ((float)numSamples - 1.0f);
    float delta_time = time / (float)numSamples;
    for ( unsigned int i=0; i<numSamples; ++i )
    {
        float yaw = delta_yaw * (float)i;
        osg::Vec3 pos( sinf(yaw)*radiusX, cosf(yaw)*radiusY, 0.0f );
        osg::Quat rot( -yaw, osg::Z_AXIS );
        path->insert( delta_time * (float)i, osg::AnimationPath::ControlPoint(pos, rot));
    }
    pathCallback->setAnimationPath( path.release() );

   transformMatrix->setUpdateCallback( pathCallback.get() );

   root->addChild( transformMatrix.get() );
}

Node * stworz_scene()
{
    Geode * geom_node = new Geode();
// slonce
    ShapeDrawable * drw = new ShapeDrawable();
    // prostopadłościan: środek i długości boków X, Y, Z
    drw->setShape(new Sphere(Vec3(0.0,0.0, 0), 109*PS));
    // kolor czerwony, w pełni nieprzezroczysty
    drw->setColor(Vec4(1.0, 1.0, 0.0, 1.0));
    geom_node->addDrawable(drw);
// merkury
    drw = new ShapeDrawable();
    // prostopadłościan: środek i długości boków X, Y, Z
    drw->setShape(new Sphere(Vec3(AU*0.3871,0.0, 0), 0.3825*PS));
    // kolor czerwony, w pełni nieprzezroczysty
    drw->setColor(Vec4(1.0, 0.9, 0.6, 1.0));
    geom_node->addDrawable(drw);
// venus
    drw = new ShapeDrawable();
    // prostopadłościan: środek i długości boków X, Y, Z
    drw->setShape(new Sphere(Vec3(AU*0.7233,0.0, 0), 0.9489*PS));
    // kolor czerwony, w pełni nieprzezroczysty
    drw->setColor(Vec4(1.0, 0.5, 0.0, 1.0));
    geom_node->addDrawable(drw);
// ziemia
    drw = new ShapeDrawable();
    // prostopadłościan: środek i długości boków X, Y, Z
    drw->setShape(new Sphere(Vec3(AU,0,0), 1.0*PS));
    // kolor czerwony, w pełni nieprzezroczysty
    drw->setColor(Vec4(0.5, 1.0, 1.0, 1.0));
    geom_node->addDrawable(drw);
// mars
   drw = new ShapeDrawable();
    // prostopadłościan: środek i długości boków X, Y, Z
    drw->setShape(new Sphere(Vec3(AU*1.5237,0.0, 0), 0.5335*PS));
    // kolor czerwony, w pełni nieprzezroczysty
    drw->setColor(Vec4(0.7, 0.0, 0.0, 1.0));
    geom_node->addDrawable(drw);
// jowisz
    drw = new ShapeDrawable();
    // prostopadłościan: środek i długości boków X, Y, Z
    drw->setShape(new Sphere(Vec3(AU*5.2034,0.0, 0), 11.2092*PS));
    // kolor czerwony, w pełni nieprzezroczysty
    drw->setColor(Vec4(1, 0.9, 0.9, 1.0));
    geom_node->addDrawable(drw);
// saturn
    drw = new ShapeDrawable();
    // prostopadłościan: środek i długości boków X, Y, Z
    drw->setShape(new Sphere(Vec3(AU*9.5372,0.0, 0.0), 9.4494*PS));
    // kolor czerwony, w pełni nieprzezroczysty
    drw->setColor(Vec4(1, 0.7, 0.4, 1.0));
    geom_node->addDrawable(drw);
// uran
    drw = new ShapeDrawable();
    // prostopadłościan: środek i długości boków X, Y, Z
    drw->setShape(new Sphere(Vec3(AU*19.1913,0.0, 0), 4.0074*PS));
    // kolor czerwony, w pełni nieprzezroczysty
    drw->setColor(Vec4(0.8, 1.0, 1.0, 1.0));
    geom_node->addDrawable(drw);
// neptun
    drw = new ShapeDrawable();
    // prostopadłościan: środek i długości boków X, Y, Z
    drw->setShape(new Sphere(Vec3(AU*30.0690,0.0, 0), 3.8827*PS));
    // kolor czerwony, w pełni nieprzezroczysty
    drw->setColor(Vec4(0.0, 0.5, 0.9, 1.0));
    geom_node->addDrawable(drw);
    

    return geom_node;
}

int main(int argc, char * argv[])
{
    Sun();
    Mercury();
    Venus();
    Earth();
    Viewer viewer;
    viewer.setUpViewInWindow(100, 100, 400, 300);
    viewer.setSceneData(root.get());
    return viewer.run();
}
