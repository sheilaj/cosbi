<?php
/**
 * @file
 * cosbi_task.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cosbi_task_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'task_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Task search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Task search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Indexed Node: Comments */
  $handler->display->display_options['relationships']['comments']['id'] = 'comments';
  $handler->display->display_options['relationships']['comments']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['relationships']['comments']['field'] = 'comments';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Status */
  $handler->display->display_options['fields']['field_task_status']['id'] = 'field_task_status';
  $handler->display->display_options['fields']['field_task_status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_task_status']['field'] = 'field_task_status';
  /* Field: Indexed Node: Assigned to */
  $handler->display->display_options['fields']['field_assigned_to']['id'] = 'field_assigned_to';
  $handler->display->display_options['fields']['field_assigned_to']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_assigned_to']['field'] = 'field_assigned_to';
  $handler->display->display_options['fields']['field_assigned_to']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_assigned_to']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_assigned_to']['bypass_access'] = 0;
  /* Field: Indexed Node: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['link_to_entity'] = 0;
  /* Field: Comment: Comment ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'entity_comment';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['relationship'] = 'comments_parent';
  $handler->display->display_options['fields']['cid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Comments */
  $handler->display->display_options['fields']['comments']['id'] = 'comments';
  $handler->display->display_options['fields']['comments']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['comments']['field'] = 'comments';
  $handler->display->display_options['fields']['comments']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['comments']['view_mode'] = 'full';
  $handler->display->display_options['fields']['comments']['bypass_access'] = 0;
  /* Sort criterion: Indexed Node: last_updated */
  $handler->display->display_options['sorts']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['sorts']['search_api_aggregation_1']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['search_api_aggregation_1']['field'] = 'search_api_aggregation_1';
  $handler->display->display_options['sorts']['search_api_aggregation_1']['order'] = 'DESC';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'task' => 'task',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'task-search';
  $export['task_search'] = $view;

  return $export;
}
