<?php

/**
 * @file
 * Administration page for toggling PHPTest module functionality.
 */

/**
 * Form Builder. Configure functionality.
 *
 * @ingroup forms
 * @see system_settings_form().
 */

function phptest_admin_settings() {
  
  $form['phptest_toggle'] = array(
    '#type' => 'radios',
    '#title' => t('Print PHP Code'),
    '#description' => t('Turn the PHP Printout On or Off'),
    '#options' => array(
      t('On'),
      t('Off')
    ),
    '#default_value' => variable_get('phptest_toggle', 0) //Defaut to On    
  );
  
  $form['#submit'][] = 'phptest_admin_settings_submit';
  return system_settings_form($form);
  
}