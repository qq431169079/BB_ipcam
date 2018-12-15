
#ifndef HIPCAM_ERROR_H
#define HIPCAM_ERROR_H

    #define IPCAM_OK                                0
    #define IPCAM_IS_NULL                           -1
    #define IPCAM_PORT_IS_ER                        -2
    #define IPCAM_TYPE_IS_ER                        -3
    #define IPCAM_USER_OR_PASSWD_IS_ER              -4
    #define IPCAM_IS_UNCONNECTED                    -12
    #define IPCAM_IS_FULL                           -13
    #define IPCAM_NUM_LIMITED_ER                    -14
    #define IPCAM_CANT_DETECT_TYPE_ER               -15
    #define IPCAM_IS_OVER                           -100
    #define IPCAM_IS_OVER_MAX_CHANNEL               -101
    
    #define IPCAM_SOCKET_INIT_OK                    1
    #define IPCAM_SOCKET_WSASTARTUP_ER              -1
    #define IPCAM_SOCKET_OPEN_CONFIG_ER             -2
    #define IPCAM_SOCKET_CONFIG_PARAM_ER            -3

    #define IPCAM_CGI_SUCCESS                       1
    #define IPCAM_CGI_OK                            0
    #define IPCAM_CGI_IP_NULL_ER                    -1
    #define IPCAM_CGI_INVALID_PORT_ER               -2
    #define IPCAM_CGI_GET_PARAM_ER                  -3
    #define IPCAM_CGI_SET_PARAM_ER                  -4
    #define IPCAM_CGI_CREATE_SOCKET_ER              -5
    #define IPCAM_CGI_CONNECT_ER                    -6
    #define IPCAM_CGI_CMD_BUFFER_NULL_ER            -7
    #define IPCAM_CGI_SOCKET_ER                     -8
    #define IPCAM_CGI_SEND_TIMEOUT_ER               -9
    #define IPCAM_CGI_RECV_TIMEOUT_ER               -10
    #define IPCAM_CGI_SEND_ER                       -11
    #define IPCAM_CGI_RECV_ER                       -12
    #define IPCAM_CGI_SET_FAILED_ER                 -13
    #define IPCAM_CGI_GET_FAILED_ER                 -14
    #define IPCAM_CGI_UNAUTHORIZED_ER               -15
    #define IPCAM_CGI_FILE_NOT_FOUND_ER             -16
    #define IPCAM_CGI_GET_BUFFER_NULL_ER            -17
    #define IPCAM_CGI_GET_NO_SUCH_PARAM_ER          -18
    #define IPCAM_CGI_SET_AUTH_PARAM_ER             -19
    #define IPCAM_CGI_ID_NOT_ALLOWED_ER             -98
    #define IPCAM_CGI_INVALID_ID_ER                 -99

	#define IPCAM_2WAYAUDIO_OK			             0
	#define IPCAM_2WAYAUDIO_LINE_BUSY               -40001
    #define IPCAM_2WAYAUDIO_LINE_CONNECT_ER         -40002
    #define IPCAM_2WAYAUDIO_LINE_REQUEST_ER         -40003
    #define IPCAM_2WAYAUDIO_SEND_HEADER_ER          -40004
    #define IPCAM_2WAYAUDIO_SEND_DATA_ER            -40005
    #define IPCAM_2WAYAUDIO_SOCKET_ER               -40006

#endif
 