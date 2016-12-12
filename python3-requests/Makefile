#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python3-requests
PKG_VERSION:=2.12.3
PKG_RELEASE:=1

PKG_SOURCE:=requests-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/d9/03/155b3e67fe35fe5b6f4227a8d9e96a14fda828b18199800d161bcefc1359
PKG_MD5SUM:=0cafdecd95a46b081dd5fcfa4978db7a

PKG_BUILD_DEPENDS:=python3-setuptools

include $(INCLUDE_DIR)/package.mk
$(call include_mk, python3-package.mk)

PKG_UNPACK:=gzip -dc $(DL_DIR)/$(PKG_SOURCE) | $(TAR) -C $(PKG_BUILD_DIR) --strip-components=1 $(TAR_OPTIONS)

define Package/$(PKG_NAME)
	SUBMENU:=Python
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=Python HTTP for Humans
	URL:=http://python-requests.org
	DEPENDS:=+python3
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/$(PKG_NAME)/description
 Requests allow you to send HTTP/1.1 requests. You can add headers,
 form data, multipart files, and parameters with simple Python dictionaries,
 and access the response data in the same way. It's powered by
 httplib and urllib3, but it does all the hard work and crazy hacks for you.
endef

define Build/Compile
	$(call Build/Compile/Py3Mod,,install \
		--prefix=/opt \
		--root=$(PKG_INSTALL_DIR) \
	)
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)$(PYTHON3_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON3_PKG_DIR)/* \
	    $(1)$(PYTHON3_PKG_DIR)/
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
