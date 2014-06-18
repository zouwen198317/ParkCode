#include "qfilecamerathread.h"

//��Ƶ�ļ��������Ƶ��ʶ��
QFileCameraThread* QFileCameraThread::pThreadInstance = NULL;

QFileCameraThread::QFileCameraThread(QObject *parent) :
    QThread(parent)
{
}

QFileCameraThread* QFileCameraThread::GetInstance( )
{
    if ( NULL == pThreadInstance ) {
        pThreadInstance = new QFileCameraThread( );
        pThreadInstance->moveToThread( pThreadInstance );
        pThreadInstance->start( );
    }

    return pThreadInstance;
}

void QFileCameraThread::run( )
{
    exec( );
}

void QFileCameraThread::customEvent( QEvent *e )
{
    QCameraEvent* pEvent = ( QCameraEvent* ) e;
    QCameraEvent::CameraEventType evtType = ( QCameraEvent::CameraEventType ) pEvent->type( );
}