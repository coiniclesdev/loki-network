/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class network_coinicles_coiniclesnet_Coiniclesnet_JNI */

#ifndef _Included_network_coinicles_coiniclesnet_Coiniclesnet_JNI
#define _Included_network_coinicles_coiniclesnet_Coiniclesnet_JNI
#ifdef __cplusplus
extern "C"
{
#endif
  /*
   * Class:     network_coinicles_coiniclesnet_Coiniclesnet_JNI
   * Method:    getABICompiledWith
   * Signature: ()Ljava/lang/String;
   */
  JNIEXPORT jstring JNICALL
  Java_network_coinicles_coiniclesnet_Coiniclesnet_1JNI_getABICompiledWith(JNIEnv *, jclass);

  /*
   * Class:     network_coinicles_coiniclesnet_Coiniclesnet_JNI
   * Method:    startCoiniclesnet
   * Signature: (Ljava/lang/String;)Ljava/lang/String;
   */
  JNIEXPORT jstring JNICALL
  Java_network_coinicles_coiniclesnet_Coiniclesnet_1JNI_startCoiniclesnet(JNIEnv *, jclass,
                                                      jstring);

  JNIEXPORT jstring JNICALL
  Java_network_coinicles_coiniclesnet_Coiniclesnet_1JNI_getIfAddr(JNIEnv *, jclass);

  JNIEXPORT jint JNICALL
  Java_network_coinicles_coiniclesnet_Coiniclesnet_1JNI_getIfRange(JNIEnv *, jclass);

  /*
   * Class:     network_coinicles_coiniclesnet_Coiniclesnet_JNI
   * Method:    stopCoiniclesnet
   * Signature: ()V
   */
  JNIEXPORT void JNICALL
  Java_network_coinicles_coiniclesnet_Coiniclesnet_1JNI_stopCoiniclesnet(JNIEnv *, jclass);

  JNIEXPORT void JNICALL
  Java_network_coinicles_coiniclesnet_Coiniclesnet_1JNI_setVPNFileDescriptor(JNIEnv *, jclass,
                                                              jint, jint);

  /*
   * Class:     network_coinicles_coiniclesnet_Coiniclesnet_JNI
   * Method:    onNetworkStateChanged
   * Signature: (Z)V
   */
  JNIEXPORT void JNICALL
  Java_network_coinicles_coiniclesnet_Coiniclesnet_1JNI_onNetworkStateChanged(JNIEnv *, jclass,
                                                               jboolean);

#ifdef __cplusplus
}
#endif
#endif
