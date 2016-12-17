#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-requests
PKG_VERSION:=2.12.4
PKG_RELEASE:=1

PKG_SOURCE:=requests-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/5b/0b/34be574b1ec997247796e5d516f3a6b6509c4e064f2885a96ed885ce7579/
PKG_MD5SUM:=acdb48888a9d3c7309da12fc7f83fedb

PKG_BUILD_DIR:=$(BUILD_DIR)/requests-$(PKG_VERSION)

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python-package.mk)

define Package/$(PKG_NAME)
	SUBMENU:=Python
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=Python HTTP for Humans
	URL:=http://python-requests.org
	DEPENDS:=+python
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/$(PKG_NAME)/description
 Requests allow you to send HTTP/1.1 requests. You can add headers,
 form data, multipart files, and parameters with simple Python dictionaries,
 and access the response data in the same way. It's powered by
 httplib and urllib3, but it does all the hard work and crazy hacks for you.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install \
		--prefix=/opt \
		--root=$(PKG_INSTALL_DIR) \
	)
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)/
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
