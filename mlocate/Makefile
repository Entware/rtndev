#
# Copyright (C) 2015-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2012

include $(TOPDIR)/rules.mk

PKG_NAME:=mlocate
PKG_VERSION:=0.26
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=https://releases.pagure.org/mlocate
PKG_HASH:=3063df79fe198fb9618e180c54baf3105b33d88fe602ff2d8570aaf944f1263e

PKG_INSTALL:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk

define Package/mlocate
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=mlocate - quickly find files on the filesystem
	URL:=https://fedorahosted.org/mlocate/
endef

define Package/mlocate/description
 Quickly find files on the filesystem based on their name mlocate is a new implementation of locate, a tool to find files
 anywhere in the filesystem based on their name, using a fixed pattern or a regular expression. Unlike other tools like find(1), locate uses
 a previously created database to perform the search, allowing queries to execute much faster. This database is updated periodically from cron.
endef

define Package/mlocate/install
	$(INSTALL_DIR) $(1)/opt/bin/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/var/mlocate
endef

$(eval $(call BuildPackage,mlocate))
