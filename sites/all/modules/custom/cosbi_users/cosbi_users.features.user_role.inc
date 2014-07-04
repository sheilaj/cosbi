<?php
/**
 * @file
 * cosbi_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function cosbi_users_user_default_roles() {
  $roles = array();

  // Exported role: developer.
  $roles['developer'] = array(
    'name' => 'developer',
    'weight' => 2,
  );

  // Exported role: member.
  $roles['member'] = array(
    'name' => 'member',
    'weight' => 3,
  );

  return $roles;
}
