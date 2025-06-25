<?php

/**
 * @file
 * Alters for material_admin theme.
 */

/**
 * Implements hook_preprocess_page_attachments_alter().
 */
function material_admin_page_attachments_alter(&$page) {
  $page['#attached']['drupalSettings']['material_admin']['material_admin_message_length'] = theme_get_setting('material_admin_message_length');
  $page['#attached']['drupalSettings']['material_admin']['material_admin_jqueryui_dialog_background'] = theme_get_setting('material_admin_jqueryui_dialog_background');
  $page['#attached']['drupalSettings']['material_admin']['material_admin_jqueryui_dialog_close'] = theme_get_setting('material_admin_jqueryui_dialog_close');
  $page['#attached']['drupalSettings']['material_admin']['material_admin_datepicker_select_years'] = theme_get_setting('material_admin_datepicker_select_years');
}
