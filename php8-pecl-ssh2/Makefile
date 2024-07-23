# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2024 Entware

include $(TOPDIR)/rules.mk

PECL_NAME:=ssh2
PECL_LONGNAME:=Bindings for the libssh2 library

PKG_VERSION:=1.4.1
PKG_RELEASE:=1

PKG_NAME:=php8-pecl-$(PECL_NAME)
PKG_SOURCE:=$(PECL_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=https://pecl.php.net/get/
PKG_HASH:=7bca5b23f731db9d8ed0aea5db9bb15da8ff133b0fbba96102b82e95da4d8764

PKG_BUILD_DIR:=$(BUILD_DIR)/pecl-php8/$(PECL_NAME)-$(PKG_VERSION)

PKG_LICENSE:=PHP-3.01
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Entware team, https://entware.net

PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(TOPDIR)/feeds/packages/lang/php8/pecl.mk

CONFIGURE_ARGS += \
	--with-ssh2=$(STAGING_DIR)/opt

$(eval $(call PHP8PECLPackage,$(PECL_NAME),$(PECL_LONGNAME),+libssh2,20))
$(eval $(call BuildPackage,$(PKG_NAME)))
