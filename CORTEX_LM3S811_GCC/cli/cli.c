/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Standard includes. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FreeRTOS+CLI includes. */
#include "FreeRTOS_CLI.h"

/* Structure that defines the "task-stats" command line command.  This generates
a table that gives information on each task in the system. */
static BaseType_t prvTaskStatsCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString );
static const CLI_Command_Definition_t xTaskStats =
{
	"task-stats", /* The command string to type. */
	"\r\ntask-stats:\r\n Displays a table showing the state of each FreeRTOS task\r\n",
	prvTaskStatsCommand, /* The function to run. */
	0 /* No parameters are expected. */
};


void RegisterCliCommands(void)
{
    
	FreeRTOS_CLIRegisterCommand( &xTaskStats );	
}




static BaseType_t prvTaskStatsCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
const char *const pcHeader = "     State   Priority  Stack    #\r\n************************************************\r\n";
BaseType_t xSpacePadding;

	/* Remove compile time warnings about unused parameters, and check the
	write buffer is not NULL.  NOTE - for simplicity, this example assumes the
	write buffer length is adequate, so does not check for buffer overflows. */
	( void ) pcCommandString;
	( void ) xWriteBufferLen;
	configASSERT( pcWriteBuffer );

	/* Generate a table of task stats. */
	strcpy( pcWriteBuffer, "Task" );
	pcWriteBuffer += strlen( pcWriteBuffer );

	/* Minus three for the null terminator and half the number of characters in
	"Task" so the column lines up with the centre of the heading. */
	configASSERT( configMAX_TASK_NAME_LEN > 3 );
	for( xSpacePadding = strlen( "Task" ); xSpacePadding < ( configMAX_TASK_NAME_LEN - 3 ); xSpacePadding++ )
	{
		/* Add a space to align columns after the task's name. */
		*pcWriteBuffer = ' ';
		pcWriteBuffer++;

		/* Ensure always terminated. */
		*pcWriteBuffer = 0x00;
	}
	strcpy( pcWriteBuffer, pcHeader );
	vTaskList( pcWriteBuffer + strlen( pcHeader ) );

	/* There is no more data to return after this single string, so return
	pdFALSE. */
	return pdFALSE;
}

