<?php
/**
 * @file
 * cosbi_contact.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cosbi_contact_taxonomy_default_vocabularies() {
  return array(
    'contact_role' => array(
      'name' => 'Contact role',
      'machine_name' => 'contact_role',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
