/**
 * @file    MapServiceConnector.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "MapServiceConnector.hpp"

#include "esri/ArcGIS_Connector.hpp"
#include "ogc/OGC_Connector.hpp"


namespace MSC{


/**********************************/
/*          Constructor           */
/**********************************/
MapServiceConnector::MapServiceConnector( Configuration const& configuration )
  : m_class_name("MapServiceConnector"),
    m_connection_manager(nullptr),
    m_configuration(configuration)
{
    // Misc Variables
    Status status;

    // Create the Connection Manager
    std::string driver_name = m_configuration.Get_Value("connector", status);
    if( status.Get_Code() == StatusCode::SUCCESS ){
        if( driver_name == "arcgis" ){
            m_connection_manager = std::make_shared<ArcGIS_Connector>(m_configuration);
        }
        else if( driver_name == "ogc" ){
            m_connection_manager = std::make_shared<OGC_Connector>(m_configuration);
        }
    }
}


/*****************************************/
/*     Connect to the Remote System      */
/*****************************************/
void MapServiceConnector::Connect( Status& status )
{
    
    // Check if the connector manager exists
    if( m_connection_manager == nullptr )
    {
        status = Status( StatusCode::NO_CONNECTOR_FOUND,
                         "Connection-Manager is currently null.");
        return;
    }

    //  Connect
    m_connection_manager->Connect( status );
    if( status.Get_Code() != StatusCode::SUCCESS ){
        return;
    }
    

    // Return success
    status = Status(StatusCode::SUCCESS);
}


/*******************************************/
/*          Disconnect the System          */
/*******************************************/
void MapServiceConnector::Disconnect( Status& status )
{
    // Default the status to success
    status = Status(StatusCode::SUCCESS);
    
    // Check if connected
    if( Is_Connected() == true ){
        m_connection_manager->Disconnect( status );
    }
}


/**********************************************/
/*         Check the Connection Status        */
/**********************************************/
bool MapServiceConnector::Is_Connected()const
{
    // Check manager if null
    if( m_connection_manager == nullptr ){
        return false;
    }

    // Check status
    return m_connection_manager->Is_Connected();
}


}  // End of Namespace MSC

