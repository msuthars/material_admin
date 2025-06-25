<?php

/**
 * @file
 * Suggestions for Material Admin.
 */

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function material_admin_theme_suggestions_page_alter(array &$suggestions, array $variables) {
  $route_match = \Drupal::routeMatch()->getRouteName();
  $portal_paths = ['user.pass', 'user.login', 'user.register'];
  if (in_array($route_match, $portal_paths, TRUE) && theme_get_setting('material_admin_portal_login')) {
    $suggestions[] = 'page__portal_login';
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function material_admin_theme_suggestions_input_alter(&$suggestions, array $variables) {
  $element = $variables['element'];
  if (isset($element['#attributes']['data-twig-suggestion'])) {
    $suggestions[] = 'input__' . $element['#type'] . '__' . $element['#attributes']['data-twig-suggestion'];
  }

  if (isset($variables['element']['#type']) && $variables['element']['#type'] == 'submit') {
    // Paragraph button.
    if (isset($variables['element']['#paragraphs_mode'])) {
      $suggestions[] = 'input__submit__paragraphs_' . $variables['element']['#paragraphs_mode'];
    }
    if (isset($variables['element']['#name']) && $variables['element']['#name'] == 'button_add_modal') {
      $suggestions[] = 'input__submit__button';
    }
  }
}

/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function material_admin_theme_suggestions_form_element_alter(array &$suggestions, array $variables, $hook) {
  if ($variables['element']['#type'] === 'select') {
    $suggestions[] = $hook . '__select';
  }

  if ($variables['element']['#type'] === 'radio' || $variables['element']['#type'] === 'checkbox') {
    $suggestions[] = 'form_element__wrapped';
  }
}

/**
 * Implements hook_theme().
 */
function material_admin_theme() {
  $path = \Drupal::service('extension.path.resolver')->getPath('theme', 'material_admin');
  return [
    // Template suggestion for the breadcrumb page title placeholder.
    'page_title__breadcrumb' => [
      'base hook' => 'page_title',
      'path' => $path . '/templates/navigation',
    ],
    'material_admin_collapsed_form' => [
      'base hook' => 'material_admin_collapsed_form',
      'path' => $path . '/templates/form',
      'variables' => [
        'children' => [],
      ],
    ],
  ];
}
