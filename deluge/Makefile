#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=deluge
PKG_VERSION:=1.3.15
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://download.deluge-torrent.org/source
PKG_HASH:=2bd239fc7ec0427302677abb86f927299aed4f043eca5d8a1bab2986b3659666


include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/deluge/Default
  SUBMENU:=BitTorrent
  SECTION:=net
  CATEGORY:=Network
  TITLE:=A lightweight BitTorrent client
  URL:=http://deluge-torrent.org/
  MAINTAINER:=Entware team, https://entware.net
endef

define Package/deluge
$(call Package/deluge/Default)
  TITLE+= (console UI & daemon)
  DEPENDS+=+python +rblibtorrent +chardet +pyxdg +python-twisted +python-pyopenssl +python-setuptools +python-service-identity
endef

define Package/deluge-ui-gtk
$(call Package/deluge/Default)
  TITLE+= (GTK+ UI)
  DEPENDS+=deluge +python-gtk
endef

define Package/deluge-ui-web
$(call Package/deluge/Default)
  TITLE+= (Web UI)
  DEPENDS+=deluge +mako
endef

define Package/deluge/description
  BitTorrent client with a client/server model.
endef

define Build/Compile
	$(call Build/Compile/PyMod,,install --prefix=/opt --root=$(PKG_INSTALL_DIR))
	$(SED) 's,#!.*,#!/opt/bin/python2.7,' $(PKG_INSTALL_DIR)/opt/bin/*
	$(SED) 's,save_config_path("deluge"),"/opt/etc/deluge",' $(PKG_INSTALL_DIR)/opt/lib/python2.7/site-packages/deluge/common.py
endef

define Package/deluge/postinst
#!/bin/sh
if [ ! -f /opt/etc/deluge/.configured ]; then
  echo "Setting default deluge ui to console ... "
  /opt/bin/deluge -s console
  touch /opt/etc/deluge/.configured
fi
endef

define Package/deluge/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/* \
	    $(1)$(PYTHON_PKG_DIR)/
	rm -rf $(1)$(PYTHON_PKG_DIR)/deluge/ui/gtkui
	rm -rf $(1)$(PYTHON_PKG_DIR)/deluge/ui/web

	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) \
	    $(PKG_INSTALL_DIR)/opt/bin/* \
	    $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S80deluged $(1)/opt/etc/init.d
	rm -rf $(1)/opt/bin/deluge-gtk
	rm -rf $(1)/opt/bin/deluge-web
endef

define Package/deluge-ui-gtk/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)/deluge/ui
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/deluge/ui/gtkui \
	    $(1)$(PYTHON_PKG_DIR)/deluge/ui/

	$(INSTALL_DIR) $(1)/usr/bin
	$(CP) \
	    $(PKG_INSTALL_DIR)/usr/bin/deluge-gtk \
	    $(1)/usr/bin/
endef

define Package/deluge-ui-web/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)/deluge/ui
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON_PKG_DIR)/deluge/ui/web \
	    $(1)$(PYTHON_PKG_DIR)/deluge/ui/

	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) \
	    $(PKG_INSTALL_DIR)/opt/bin/deluge-web \
	    $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S81deluge-web $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/deluge-web-reset_password $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/deluge/state
endef

$(eval $(call BuildPackage,deluge))
#$(eval $(call BuildPackage,deluge-ui-gtk))
$(eval $(call BuildPackage,deluge-ui-web))
