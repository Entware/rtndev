# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2022-2025 Entware

include $(TOPDIR)/rules.mk

PECL_NAME:=event
PECL_LONGNAME:=Provides interface to libevent library

PKG_VERSION:=3.1.4
PKG_RELEASE:=1

PKG_NAME:=php8-pecl-$(PECL_NAME)
PKG_SOURCE:=$(PECL_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=https://pecl.php.net/get
PKG_HASH:=5c4caa73bc2dceee31092ff9192139df28e9a80f1147ade0dfe869db2e4ddfd3

PKG_BUILD_DIR:=$(BUILD_DIR)/pecl-php8/$(PECL_NAME)-$(PKG_VERSION)

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=PHP-3.01
PKG_LICENSE_FILES:=LICENSE

PKG_BUILD_DEPENDS:=php8
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk
include $(TOPDIR)/feeds/packages/lang/php8/pecl.mk

CONFIGURE_ARGS += \
	--with-event-libevent-dir=$(STAGING_DIR)/opt \
	--with-event-pthreads

$(eval $(call PHP8PECLPackage,$(PECL_NAME),$(PECL_LONGNAME),+libevent2-extra +libevent2-openssl +libevent2-pthreads +php8-mod-sockets,30))
$(eval $(call BuildPackage,$(PKG_NAME)))
