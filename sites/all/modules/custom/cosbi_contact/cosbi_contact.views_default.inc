<?php
/**
 * @file
 * cosbi_contact.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cosbi_contact_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_email' => 'field_email',
    'field_phone' => 'field_phone',
    'field_contact_role' => 'field_contact_role',
    'field_skills' => 'field_skills',
    'field_connection' => 'field_connection',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contact_role' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_skills' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_connection' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: Content: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: Content: email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  /* Field: Content: Potential role(s) */
  $handler->display->display_options['fields']['field_contact_role']['id'] = 'field_contact_role';
  $handler->display->display_options['fields']['field_contact_role']['table'] = 'field_data_field_contact_role';
  $handler->display->display_options['fields']['field_contact_role']['field'] = 'field_contact_role';
  $handler->display->display_options['fields']['field_contact_role']['delta_offset'] = '0';
  /* Field: Content: Skills & financial */
  $handler->display->display_options['fields']['field_skills']['id'] = 'field_skills';
  $handler->display->display_options['fields']['field_skills']['table'] = 'field_data_field_skills';
  $handler->display->display_options['fields']['field_skills']['field'] = 'field_skills';
  /* Field: Content: Connection */
  $handler->display->display_options['fields']['field_connection']['id'] = 'field_connection';
  $handler->display->display_options['fields']['field_connection']['table'] = 'field_data_field_connection';
  $handler->display->display_options['fields']['field_connection']['field'] = 'field_connection';
  $handler->display->display_options['fields']['field_connection']['settings'] = array(
    'link' => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'contact' => 'contact',
  );
  /* Filter criterion: Content: Potential role(s) (field_contact_role) */
  $handler->display->display_options['filters']['field_contact_role_tid']['id'] = 'field_contact_role_tid';
  $handler->display->display_options['filters']['field_contact_role_tid']['table'] = 'field_data_field_contact_role';
  $handler->display->display_options['filters']['field_contact_role_tid']['field'] = 'field_contact_role_tid';
  $handler->display->display_options['filters']['field_contact_role_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_role_tid']['expose']['operator_id'] = 'field_contact_role_tid_op';
  $handler->display->display_options['filters']['field_contact_role_tid']['expose']['label'] = 'Role';
  $handler->display->display_options['filters']['field_contact_role_tid']['expose']['operator'] = 'field_contact_role_tid_op';
  $handler->display->display_options['filters']['field_contact_role_tid']['expose']['identifier'] = 'field_contact_role_tid';
  $handler->display->display_options['filters']['field_contact_role_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_contact_role_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_role_tid']['vocabulary'] = 'contact_role';
  /* Filter criterion: Content: Last name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_field'] = 'field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: First name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_field'] = 'field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['autocomplete_dependent'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['contacts'] = $view;

  return $export;
}
