<?php

/**
 * @file
 * Administration page for toggling test module functionality.
 */

/**
 * Form Builder. Configure functionality.
 *
 * @ingroup forms
 * @see system_settings_form().
 */

function annotate_admin_settings() {
  
  $types = node_type_get_types();
  
  foreach ($types as $node_type) {
    $options[$node_type->type] = $node_type->name;
  };
  
  $form['annotate_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node Type Selection'),
    '#description' => t('Choose for which Node Types you want to use Annotation'),
    '#options' => $options,
    '#default_value' => variable_get('annotate_node_types', array('page')) //Defaut to Pages    
  );
  
  $form['#submit'][] = 'annotate_admin_settings_submit';
  
  return system_settings_form($form);
  
}

/**
 * Form submission for Annotate Settings
 */

function annotate_admin_settings_submit($form, $form_state) {
  
  foreach ($form_state['values']['annotate_node_types'] as $key => $value) {
    if (!$value) {
      $instance = field_info_instance('node', 'annotation', $key);
      if (!empty($instance)) {
        field_delete_instance($instance);
        watchdog(
          "Annotation",
          'Deleted annotation field from content type: %key',
          array('%key' => $key)
        ); 
      }
    } else {
      $instance = field_info_instance('node', 'annotation', $key);
      if (empty($instance)) {
        $instance = array(
          'field_name' => 'annotation',
          'entity_type' => 'node',
          'bundle' => $key,
          'lable' => t('Annotation'),
          'widget_type' => 'text_textarea_with_summary',
          'settings' => array('display_summary' => TRUE),
          'display' => array(
            'default' => array(
              'type' => 'text_default'
            ),
            'teaser' => array(
              'type' => 'text_summary'
            )
          )       
        );
        $instance = field_create_instance($instance);
        watchdog(
          'Annotation',
          'Added annotation field to content type: %key',
          array('%key' => $key)
        ); 
      }  
    }
  } //End of foreach loop
}

  