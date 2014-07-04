<?php
/**
 * @file
 * cosbi_contact.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cosbi_contact_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cosbi_contact_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cosbi_contact_node_info() {
  $items = array(
    'contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => t('A contact may be a potential investor, resource or member.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('For now, enter contact\'s full name for the title. I will automate this later.'),
    ),
  );
  return $items;
}
