#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-onedrive
PKG_VERSION:=15.10.5
PKG_RELEASE:=1

PYPI_NAME:=$(PKG_NAME)
PKG_HASH:=d76f3623eb3063a9f0164f1a4e7bfa23ee4c99db812fb45661d4c4bd84bccef8

#include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
#include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/$(PKG_NAME)
	SUBMENU:=Python
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=Python and CLI interface to MS OneDrive REST API v5.0
	URL:=https://github.com/mk-fg/python-onedrive
#	DEPENDS:=+python-requests +python-yaml
	MAINTAINER:=Entware team, https://entware.net
	VARIANT:=python
endef

define Package/$(PKG_NAME)/description
 Python and command-line interface for Microsoft LiveConnect OneDrive
 REST API v5.0.
endef

#$(eval $(call PyPackage,$(PKG_NAME)))
#$(eval $(call BuildPackage,$(PKG_NAME)))
