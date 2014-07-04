<?php
/**
 * @file
 * cosbi_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cosbi_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function cosbi_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "CoSBi index",
    "machine_name" : "default_node_index",
    "description" : "CoSBi index of all node content.",
    "server" : "cosbi",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "last_updated",
                "type" : "max",
                "fields" : [ "changed", "comments:created" ],
                "description" : "A Maximum aggregation of the following fields: Date changed, Comments \\u00bb Date created."
              },
              "search_api_aggregation_2" : {
                "name" : "last_updated_field",
                "type" : "fulltext",
                "fields" : [ "search_api_aggregation_1" ],
                "description" : "A Fulltext aggregation of the following fields: last_updated."
              }
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_skills" : true,
              "body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_skills" : true,
              "body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_skills" : true,
              "body:value" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_first_name" : true,
              "field_last_name" : true,
              "field_skills" : true,
              "body:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "comments" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "comment" },
        "comments:cid" : { "type" : "list\\u003Cinteger\\u003E" },
        "comments:parent" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "comment" },
        "created" : { "type" : "date" },
        "field_assigned_to" : { "type" : "integer", "entity_type" : "user" },
        "field_connection" : { "type" : "integer", "entity_type" : "user" },
        "field_contact_role" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_first_name" : { "type" : "text" },
        "field_last_name" : { "type" : "text" },
        "field_priority" : { "type" : "string" },
        "field_skills" : { "type" : "text" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_task_status" : { "type" : "string" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "date" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function cosbi_search_default_search_api_server() {
  $items = array();
  $items['cosbi'] = entity_import('search_api_server', '{
    "name" : "CoSBi",
    "machine_name" : "cosbi",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 1,
      "indexes" : { "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_default_node_index",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_connection" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_connection",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_contact_role" : {
            "table" : "search_api_db_default_node_index_field_contact_role",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_first_name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_last_name" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_skills" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_assigned_to" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_assigned_to",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_task_status" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_task_status",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_priority" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_priority",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_tags" : {
            "table" : "search_api_db_default_node_index_field_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_default_node_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "comments" : {
            "table" : "search_api_db_default_node_index_comments",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_aggregation_1" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_aggregation_1",
            "type" : "date",
            "boost" : "1.0"
          },
          "comments:cid" : {
            "table" : "search_api_db_default_node_index_comments_cid",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "comments:parent" : {
            "table" : "search_api_db_default_node_index_comments_parent",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
